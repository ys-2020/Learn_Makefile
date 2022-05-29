# filter 函数从⼀个字符串中，根据模式得到满足条件的字符串
# 其形式是：$(filter pattern..., text)

.PHONY: all
sources = foo.c bar.c baz.s ugh.h
sources := $(filter %.c %.s, $(sources))
all:
	@echo $(sources)