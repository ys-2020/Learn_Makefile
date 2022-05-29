# 模式
# 对于每⼀个目标文件都得写⼀个不同的规则来描述，很不方便
# 模式可解决这一问题
# 模式类似于 Windows 中的通配符，用“%”表示
# 可以用同一个模式编译所有的源文件

.PHONY: clean
Compiler = g++
RM = rm
EXE = addtest
OBJS = main.o add.o
$(EXE): $(OBJS)
	$(Compiler) -o $@ $^
%.o: %.c
	$(Compiler) -o $@ -c $^
clean:
	$(RM) $(EXE) $(OBJS)




