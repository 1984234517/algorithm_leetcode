#include <iostream>
#include <vector>

using namespace std;

// constexpr修饰普通变量
void test1(){
    constexpr int n=1+2+3;
    int res[n]={0};
    cout<<res[2]<<endl;
}
// constexpr修饰函数
constexpr int test2(int x){
    int ret = 1+2+x;
    return ret;
}

// constexpr修饰类
//自定义类型的定义，报错
// constexpr struct myType {
//     const char* name;
//     int age;
//     //其它结构体成员
// };

// 正确使用
//自定义类型的定义
struct myType {
    constexpr myType(char *name,int age):name(name),age(age){};
    const char* name;
    int age;
    //其它结构体成员
};
int main(){
    test1();
    cout<<test2(23)<<endl;
    return 0;
}