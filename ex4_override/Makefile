# Override指令
# 在设计 Makefile 时，我们并不希望用户将我们在 Makefile 中定义的某个变量覆盖掉
# 用 override 指令实现这一目标

.PHONY: all
override foo = x
# foo = x
all:
	@echo "foo = $(foo)"

# make foo=abc

