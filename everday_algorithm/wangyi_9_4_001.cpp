#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k,t;
    cin>>n>>k>>t;
    if(k<t+1 || n-k<k-1-t){
        cout<<-1<<endl;
        return 0;
    }
    string res = "";
    for(int i=0;i<t+1;i++){
        res+='1';
    }
    // 剩余1的个数
    int one = k-t-1;
    // 剩余0的个数
    int zero = n-k;
    for(int i=0;i<min(one,zero);i++){
        res+='0';
        res+='1';
    }
    zero-=min(one,zero);
    for(int i=0;i<zero;i++)
        res+='0';
    cout<<res<<endl;
    return 0;
}
