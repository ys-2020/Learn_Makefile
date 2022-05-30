.PHONY:all clean

MKDIR=mkdir
RM=rm
RMFLAGS=-fr

Compiler=g++

DIR_OBJS=objs
DIR_EXE=exes
DIR_DEPS=deps
DIRS=$(DIR_OBJS) $(DIR_EXE) $(DIR_DEPS)

EXE=test
EXE:=$(addprefix $(DIR_EXE)/, $(EXE)) #增加路径前缀

SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=.o)	# .cpp后缀替换为 .o
OBJS:=$(addprefix $(DIR_OBJS)/, $(OBJS))

DEPS = $(SRCS:.cpp=.dep)  # .cpp后缀替换为 .dep
DEPS := $(addprefix $(DIR_DEPS)/, $(DEPS))

CLEANTMP = cleantmp


# include在all的相应实现依赖之前就被执行
# 原来的实现中, deps文件夹的创建和.dep文件的创建分属两个依赖,所以include会在.dep文件创建前就开始搜索
# 所以我们需要对 Makefile 的依赖关系进行调整
# 即将 deps 目录的创建放在构建依赖之前

all:$(EXE) $(CLEANTMP)
 
include $(DEPS)

$(DIRS):
	$(MKDIR) $@

$(EXE):$(DIR_EXE) $(OBJS)
	$(Compiler) -o $@ $(filter %.o, $^)

# 第一个依赖是 $(DIR_OBJS), 先mkdir 
# 第二个依赖是 %.cpp 对 cpp进行编译
$(DIR_OBJS)/%.o:$(DIR_OBJS) %.cpp  
	$(Compiler) -o $@ -c $(filter %.cpp, $^)

$(DIR_DEPS)/%.dep:$(DIR_DEPS) %.cpp
	@echo "Making $@ ..."
	@set -e;\
	$(Compiler) -E -MM $(filter %.cpp,$^) > $@.tmp ; \
	sed 's,\(.*\)\.o[ :]*,objs/\1.o: ,g' < $@.tmp > $@ ;

# 原网页的代码有较大问题, $(DIR_DEPS)被放进编译器处理了, 会报错
# 且程序会陷入死循环, 因为 $(DIR_DEPS)会一直被rm .tmp更新
# 我们在编译处filter出.cpp
# 并将rm .tmp工作放到最后完成


# 原网页写法如下：
# $(DIR_DEPS)/%.dep:$(DIR_DEPS) %.c
# 	@echo "Making $@ ..."
# 	@set -e; \
# 	$(RM) $(RMFLAGS) $@.tmp ; \
# 	$(CC) -E -MM $(filter %.c, $^) > $@.tmp ; \
# 	sed 's,\(.*\)\.o[ :]*,objs/\1.o: ,g' < $@.tmp > $@ ; \
# 	$(RM) $(RMFLAGS) $@.tmp

cleantmp:
	@$(RM) $(RMFLAGS) $(addsuffix .tmp,$(DEPS))

clean:
	$(RM) $(RMFLAGS) $(DIRS)

