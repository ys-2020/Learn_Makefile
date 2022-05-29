# wildcard 是通配符函数，通过它可以得到我们所需的文件
# 这个函数类似于 Windows 或 Linux 命令行中的“*”
# 其形式是：$(wildcard pattern)

.PHONY:all
SRC=$(wildcard *.c *.py)
all:
	@echo "SRC = $(SRC)"

# 文件夹中有 test.c myfun.cpp main.c add.py
# 输出 main.c test.c add.py