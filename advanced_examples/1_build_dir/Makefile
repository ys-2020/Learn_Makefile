# 利用 Makefile 创建目录
.PHONY:all
.PHONY:clean

MKDIR=mkdir
DIRS=objs exes
RMR=rm -r
all:$(DIRS)
# $(DIRS)表示依赖,故不换行

$(DIRS):
	$(MKDIR) $@

clean:$(DIRS)
	$(RMR) $^