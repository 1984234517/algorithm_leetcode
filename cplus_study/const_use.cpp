#include <iostream>

using namespace std;


// const修饰全局变量
// 在c++和c中是都不能使用指针来修改的
// const修饰局部变量
// c中是可以使用
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