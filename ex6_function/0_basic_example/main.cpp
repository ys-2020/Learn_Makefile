#include<iostream>
using namespace std;
// #include"add.cpp" // 一般的调用方法，Makefile + extern C 可以不这么搞


extern int add(int a,int b);


int main()
{
    int c = add(1,3);
    cout << c <<endl;
    return 0;
}
