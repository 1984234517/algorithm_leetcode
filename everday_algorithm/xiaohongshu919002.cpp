#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    vector<int> dp(n,1000000000);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=max(0,i-k);j--){
            if(nums[i]<nums[j]){
                dp[i]=min(dp[i],dp[j]);
            }else{
                dp[i]=min(dp[i],dp[j]+nums[i]-nums[j]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
