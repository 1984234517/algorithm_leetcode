#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int res=0;
    for(int i=n;i>=1;i--){
        res+=log2(i);
    }
    cout<<res<<endl;
    return 0;
}
