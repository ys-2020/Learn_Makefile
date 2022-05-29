# filter-out 函数从⼀个字符串中根据模式滤除⼀部分字符串
# 其形式是：$(filter-out pattern..., text)

.PHONY: all
objects = main1.o foo.o main.o main21.o bar.o
result := $(filter-out main%.o, $(objects))
all:
	@echo $(result)