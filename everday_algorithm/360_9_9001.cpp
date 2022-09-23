#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long res = 0;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        res+=nums[i];
    }
    // 只有一发子弹打中
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            res+=(nums[i]|nums[j]);
    }
    cout<<res<<endl;
    return 0;
}
