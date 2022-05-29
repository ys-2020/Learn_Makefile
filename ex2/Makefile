.PHONY: clean # 将 clean 声明为假目标，即使有 clean 文件存在，依然可以make clean
all: main.o add.o
	g++ -o addtest main.o add.o
main.o: main.cpp
	g++ -o main.o -c main.cpp
add.o: add.cpp
	g++ -o add.o -c add.cpp	
clean:
	rm addtest main.o add.o
