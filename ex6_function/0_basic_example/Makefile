# 函数
# 函数是 Makefile 中的另⼀个利器
# 对于 addtest 项⽬的 Makefile，尽管我们使用了模式规则，但还有⼀件⽐较恼人的事：
# 我们得在 Makefile 中指明每⼀个需要被编译的源程序

# 采采用 wildcard 和 patsubst 两个函数可以解决这个问题,下面是一个例子：

.PHONY: clean
Compiler = g++
RM = rm
EXE = addtest
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
$(EXE): $(OBJS)
	$(Compiler) -o $@ $^
%.o: %.c
	$(Compiler) -o $@ -c $^
clean:
	$(RM) $(EXE) $(OBJS)

# wildcard 和 patsubst 的具体用法在后面介绍


