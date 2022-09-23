#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    vector<int> nums;
    while(cin>>a){
        nums.push_back(a);
        if(cin.get()=='\n')
            break;
    }
    cin>>a;
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(a+1));
    vector<vector<bool>> vis(n,vector<bool>(a+1));
    for(int i=0;i<n;i++){
        for(int j=1;j<=a;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=nums[i]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-nums[i]]+1);
                if(dp[i][j]>dp[i-1][j-nums[i]]+1){
                    dp[i][j] = dp[i-1][j-nums[i]]+1;
                    vis[i][j]=1;
                }
            }
        }
    }
    return 0;
}
