#include <iostream>

using namespace std;

class A{
    int a;
    public:
    int b;
    protected:
    int c;
};

// 私有继承的含义就是，把父类中的成员变量全部当成private变量，但是记住一点
// 如果某个变量在父类中已经是private变量，那么在子类中是无法访问这个变量的
class B:private A{
    public:
        void f1(){
            cout<<b<<endl;
        }
};

int main(){
    B b;
    b.f1();
    return 0;
}