.PHONY: clean
Compiler = g++
RM = rm
EXE = addtest
OBJS = main.o add.o
$(EXE): $(OBJS)	
	$(Compiler) -o $(EXE) $(OBJS)
main.o: main.cpp	
	$(Compiler) -o main.o -c main.cpp
add.o: add.cpp	
	$(Compiler) -o add.o -c add.cpp
clean:	
	$(RM) $(EXE) $(OBJS)