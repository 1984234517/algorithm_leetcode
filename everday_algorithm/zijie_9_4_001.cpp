#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int res = 0;
    vector<vector<int>> nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>nums[i][j];
    }
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<m;i++){
        if(nums[0][i]!=-1)
            dp[0][i]=nums[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            // 上,左上，右上
            int top=-1,l=-1,r=-1;
            if(nums[i-1][j]!=-1)
                top=dp[i-1][j];
            if(j>0 && nums[i-1][j-1]==-1)
                l = dp[i-1][j-1];
            if(j+1<m && nums[i-1][j+1]==-1){
                r = dp[i-1][j+1];
            }
            dp[i][j] = max(top,max(l,r));
            if(dp[i][j] != -1 && nums[i][j]!=-1)
                dp[i][j]+=nums[i][j];
            if(i==n-1 && res<dp[i][j])
                res = dp[i][j];
        }
    }
    cout<<res<<endl;
    return 0;
}
