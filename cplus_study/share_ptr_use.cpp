#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<int> make(int value){
    return shared_ptr<int>(new int(value));
}

void test02(){
    shared_ptr<int> pi1(new int(100)); //裸指针初始化，pi指向一个值为100的int型数据
    shared_ptr<int> pi2 = make(200);//返回值初始化
    shared_ptr<string> pi3(new string("sdfdsf"));
    cout<< (*pi1.get()) << endl;
    cout<< (*pi2.get()) << endl;
    cout<<*pi3.get()->data()<<endl;
    cout<< pi1.use_count() << endl;
    cout<< pi2.use_count() << endl;
    int* pp = new int[3];
    pp[0] = 1;
    pp[1] = 2;
    pp[2] = 3;
    shared_ptr<int> ss(pp,[](int* ptr){delete[] ptr;ptr=nullptr;});
    cout<<ss.get()[2]<<endl;
}

int main(){

    test02();

    return 0;
}
