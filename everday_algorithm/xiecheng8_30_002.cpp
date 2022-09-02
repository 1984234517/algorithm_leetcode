#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int res=0;
        int minVal = min(a,min(b,c));
        res+=2*minVal;
        res+=max(0,(b-minVal)-1);
        cout<<res<<endl;
    }
    return 0;
}
