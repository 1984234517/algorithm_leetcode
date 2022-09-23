#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int base = 100004;
    vector<int> dp(100004);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=base;i++){
        dp[i]=dp[i-1]+1;
        for(int j=sqrt(i);j>=2;j--){
            if(i%j==0)
                dp[i]=min(dp[i],dp[j]+dp[i/j]+1);
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res+=dp[nums[i]];
    }
    cout<<res<<endl;
    return 0;
}
