#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 最简单的线段树，用来解决单点修改，区间查询

// 建树

// buildTree()

// 单点修改

// 区间查询

char* getRes(){
    char se[] = "hello world";
    return se;
}

char* getRe(){
    return "hello world";
}

void print(){
    char* str = NULL;
    // 因为接收的是函数中的se的值，这个se所拥有的空间在getRes结束后，就将空间释放了，所以
    // 因为这时的getRes返回的是一个char*变量，所以就是变量之间se和str之间的赋值，
    // 但是因为se离开函数getRes后，空间被释放了，成立一个悬空指针，导致str也成了一个悬空指针
    str = getRes();
    // 因为函数返回的是一个字符串常量值，所以在print函数中会为这个字符串常量值申请一个空间，
    // (因为是常量值，并没有在赋值这一行后空间释放掉)
    str = getRe();
    cout<<str<<endl;
}

void getRes1(char* p){
    p = (char*) malloc(100);
}

void print1(){
    char* str = nullptr;
    getRes1(str);
    strcpy(str,"hello world");
    cout<<str<<endl;
}

int main(int argc, char const *argv[])
{
    // print1();
    print();
    return 0;
}
