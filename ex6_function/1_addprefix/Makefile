# addprefix 函数给字符串中的每个子串前加上⼀个前缀
# 其形式是：$(addprefix prefix, names...)

.PHONY:all
without_dir= foo.c bar.c main.c
with_dir:=$(addprefix objs/, $(without_dir))
all:
	@echo $(with_dir)