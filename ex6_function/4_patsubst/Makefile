# patsubst 函数实现字符串替换
# 其形式是：$(patsubst pattern, replacement, text)

.PHONY:all
mixed=foo.c bar.c main.o
objects:=$(patsubst %.c, %.o, $(mixed))
all:
	@echo $(objects)

# 将 .c 改成 .o