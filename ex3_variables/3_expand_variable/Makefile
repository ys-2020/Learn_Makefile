.PHONY: clean
.PHONY: all

# 递归扩展变量
# 使用等号进行变量定义和赋值
# 对于这种只用⼀个“=”符号定义的变量，我们称之为递归扩展变量（recursively expanded variable）
a = $(b)
b = $(c)
d = Hello world!
c = $(d)
recur:
	@echo $(a)


# 简单扩展变量
# 用“:=”操作符定义
# 对于这种变量, make 只对其进⾏⼀次扫描和替换
x = recursive expanded variable x
y = $(x) b
x = later

xx := simple expanded variable xx
yy := $(xx) b
xx := later
simple:
	@echo "y = $(y)" 
	@echo "yy = $(yy)"


# 条件赋值符？=
# 当变量以前没有定义时，就定义它并且将左边的值赋值给它
# 如果已经定义了那么就不再改变其值
foo = x
foo ?= y
bar ?= y
cond:
	@echo "foo = $(foo), bar = $(bar)"


# +=操作符
objects = main.o foo.o bar.o utils.o
objects += another.o
selfadd:
	@echo $(objects)