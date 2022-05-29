# 自动变量示例

# .PHONY:all
# all:first second third
# 	@echo "\$$@ = $@"
# 	@echo "\$$^ = $^"
# 	@echo "\$$< = $<"
 
# first:

# second:

# third:

# 用自动变量实现ex3


.PHONY: clean
Compiler = g++
RM = rm
EXE = addtest
OBJS = main.o add.o
$(EXE): $(OBJS)
	$(Compiler) -o $@ $^
main.o: main.cpp
	$(Compiler) -o $@ -c $^
add.o: add.cpp
	$(Compiler) -o $@ -c $^
clean:
	$(RM) $(EXE) $(OBJS)
