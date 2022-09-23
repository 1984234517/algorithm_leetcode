#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int base = 1000000007;
vector<int> nums;

vector<long long> dfs(int k,vector<vector<int>>& dp){
    int res = 0;
    long long mul=1;
    for(int i=0;i<dp[k].size();i++){
        auto it = dfs(dp[k][i],dp);
        res = (0LL+res+it[0])%base;
        mul*=it[1];
    }
    mul*=nums[k];
    for(int i=sqrt(mul);i>=1;--i){
        if(mul%i==0){
            res=(0LL+res+2)%base;
        }
    }
    return {res,mul};
}
int main(){
    int n;
    cin>>n;
    nums.resize(n);
    vector<vector<int>> dp(n,vector<int>());
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int s,e;
    for(int i=0;i<n-1;i++){
        cin>>s>>e;
        dp[s-1].push_back(e-1);
    }
    cout<<dfs(0,dp)[0]<<endl;
    return 0;
}