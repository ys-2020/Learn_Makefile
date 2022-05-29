.PHONY:all clean

MKDIR=mkdir
RM=rm
RMFLAGS=-r

Compiler=g++

DIR_OBJS=objs
DIR_EXE=exes
DIRS=$(DIR_OBJS) $(DIR_EXE)

EXE=test
EXE:=$(addprefix $(DIR_EXE)/, $(EXE)) #增加路径前缀

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)	# .cpp后缀替换为 .o
OBJS:=$(addprefix $(DIR_OBJS)/, $(OBJS))

all:$(DIRS) $(EXE)

$(DIRS):
	$(MKDIR) $@

$(EXE):$(OBJS)
	$(Compiler) -o $@ $^

$(DIR_OBJS)/%.o:%.cpp
	$(Compiler) -o $@ -c $^

clean:
	$(RM) $(RMFLAGS) $(DIRS)