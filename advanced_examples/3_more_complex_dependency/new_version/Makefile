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

all:$(DIRS) $(DEPS) $(EXE)

$(DIRS):
	$(MKDIR) $@

$(EXE):$(OBJS)
	$(Compiler) -o $@ $^

$(DIR_OBJS)/%.o:%.cpp
	$(Compiler) -o $@ -c $^

$(DIR_DEPS)/%.dep: %.cpp
	@echo "Making $@ ..."
	@set -e;\
	$(RM) $(RMFLAGS) $@.tmp ; \
	$(Compiler) -MM $^ > $@.tmp ; \
	sed 's,\(.*\)\.o[ :]*,objs/\1.o: ,g' < $@.tmp > $@ ; \
	$(RM) $(RMFLAGS) $@.tmp
# 依赖先写入.tmp, 修改后写到.dep中
# 原网页中 g++ 带了-E, 则只依赖不编译, 不能解决.h变动后编译不报错的问题
# 不过原网页在后续部分用另外方法处理了这一问题,事实上我们去掉-E也可以解决

clean:
	$(RM) $(RMFLAGS) $(DIRS)


