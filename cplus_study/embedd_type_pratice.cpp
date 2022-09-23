#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

template<class T>
T get(T i){
    return i;
}

int main(int argc, char const *argv[])
{
    // shared_ptr<int> st(new int(23));
    const int a = 1+23+4;
    cout<<a<<endl;
    auto it = get<int*>(new int(23));
    cout<<*it<<endl;
    cout<<typeid(it).name()<<endl;
    return 0;
}
