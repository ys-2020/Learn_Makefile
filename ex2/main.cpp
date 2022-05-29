#include<iostream>
using namespace std;
// #include"add.cpp" 

extern int add(int a,int b);

int main()
{
    int c = add(1,3);
    cout << c <<endl;
    return 0;
}
