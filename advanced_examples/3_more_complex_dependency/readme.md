# More Complex Dependency

首先转入old_version文件夹，make 可正常编译代码

然后修改add.h中add函数的声明为：

int add(int a);

这与add.cpp不一致

重新make,提示 Nothing to be done for 'all'(我们预期这里编译应当报错)

显然,Makefile没有检查.h的依赖

make clean & make, 编译器正确报错

我们需要完善文件的依赖关系(增加对.h的依赖)

修改后的版本在new_version文件夹中

其主要思路如下：

一个简单的方法是,将\$(DIR_OBJS)/\%.o:\%.cpp 修改为 \$(DIR\_OBJS)/\%.o:\%.cpp add.h
并将最后的 \$\^ 改为 \$\< (我们不想把.h也送给g++编译)
但是,当.h文件较多时,这种方法很不方便

事实上, gcc/g++ 可以动态生成文件的依赖关系
利用 gcc/g++ 的-M 选项和-MM 选项可以列出 .c/.cpp 文件的所有依赖关系
-MM 选项与-M 选项的区别是，-MM选项并不列出对于系统头文件的依赖关系
e.g. g++ -MM main.cpp 的输出是： main.o: main.cpp add.h

对于 g++ -MM 的结果, 还有⼀个问题, 因为我们将生成的目标文件放在objs目录中,
我们希望依赖关系中也包含这⼀目录信息,
否则,在 Makefile 中,我们没有办法将生成的目标文件放进objs目录。
这是,我们需要用到 sed 工具, 用于查找和替换 g++ 的输出结果
例如：
		g++ -MM main.cpp | sed 's,\(.*\)\.o[ :]*,objs/\1.o: ,g'
可将输出路径改为objs文件夹

现在,我们已经有了自动生成依赖关系的⽅法了，那如何将其整合到 Makefile 中呢？
我们只需为每⼀个源文件通过生成⼀个依赖关系文件，采用.dep 后缀结尾。
从模块化的角度来说, 我们不希望.dep文件与.o 文件或是可执⾏文件混放在⼀个⽬录中。
为此,我们创建一个新的 deps 目录存放.dep文件。
然后利用.dep文件,获取依赖关系。

注意：原网址中此处有些小问题，详见Makefile注释
