# 当 Makefile 的条件语法包括 ifdef、ifeq、ifndef 和 ifneq 四种语句形式。

# 需要注意的是,自动变量(如@,$^)不能用于条件语法语句块中,因为自动变量在命令处理阶段才赋值
# 如果要对自动变量使用条件语法,需要借助于 Shell 而不是 Makefile

.PHONY: all
sharp = square
desk = square
table = circle

 
ifeq ($(sharp), $(desk))
	result1 := "desk == sharp"
endif

ifneq "$(table)" "square"
	result2 := "table != square"
endif
all:
	@echo $(result1)
	@echo $(result2)
