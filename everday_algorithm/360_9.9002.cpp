#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> nums(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>nums[i][j];
        }
        int k = min(m,n);
        int maxV = -1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int t=0;t<=min(i,j);t++){
                    if(nums[i][j]==-1){
                        dp[i][j][t]=-1;
                        continue;
                    }
                    if(t==0){
                        dp[i][j][t]=nums[i][j];
                    }else{
                        if(i>0 && j>0 && nums[i-1][j]!=-1 && nums[i][j-1]!=-1 && dp[i-1][j-1][t-1]!=-1)
                            dp[i][j][t]=dp[i-1][j-1][t-1]+nums[i][j]+nums[i-1][j]+nums[i][j-1];
                        else{
                            dp[i][j][t]=-1;
                            continue;
                        }
                    }
                    if(maxV<t)
                        maxV=t;
                }
            }
        }
        int res = 0;
        if(maxV<0){
            cout<<res<<endl;
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res<dp[i][j][maxV])
                    res = dp[i][j][maxV];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
