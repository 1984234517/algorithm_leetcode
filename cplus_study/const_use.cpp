#include <iostream>

using namespace std;


// const修饰全局变量
// ----在c++和c中是都不能使用指针来修改的
// const修饰局部变量
// ----c中会为这个局部变量在栈中申请一个空间，所以可以使用指针来修改
// ----c++中有区分，如果const int a=23，也就是a后面初始给的是一个常量
// ----变量a就会放入符号表中(不会分配空间)，如果后面需要访问a的地址(这个时候)
// 在c++和c中，const修饰的全局变量是不能使用指针来修改的

int main(int argc,char* argv[]){
    int b=23;
    const int a=27;
    int * p = (int*) &a;
    *p=24;
    cout<<a<<endl;
    cout<<*(&a)<<endl;
    return 0;
}