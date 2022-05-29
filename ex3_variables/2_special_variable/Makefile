.PHONY: clean
.PHONY: all

# MAKECMDGOALS变量
# 它表示的是当前用户所输⼊的 make 目标是什么
# all clean可由make all, make clean触发, make all clean可触发两次
all clean:
	@echo "\$$@ = $@"
	@echo "MAKECMDGOALS = $(MAKECMDGOALS)"


# 特殊变量类型：MAKE
# 表示make命令名是什么
# 当我们在 Makefile 中调用另⼀个 Makefile 时需要用到这个变量，有利于写⼀个可移植的 Makefile
make_var:
	@echo "MAKE = $(MAKE)"

