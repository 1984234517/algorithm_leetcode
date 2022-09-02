#include <iostream>

using namespace std;

class Base{
    public:
        virtual void sleep(){
            cout<<"Base::"<<endl;
        }
        void func(){
            sleep();
        }
};

class Son:public Base{
    public:
        virtual void sleep(){
            cout<<"Son"<<endl;
        }
        void func(){
            sleep();
        }
};

int main(int argc, char const *argv[])
{
    Son son;
    Base* p = new Base();
    p = &son;
    ((Base*)(&son))->sleep();
    return 0;
}
