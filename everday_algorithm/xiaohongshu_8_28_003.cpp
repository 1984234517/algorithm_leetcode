#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int in,vector<vector<int>>& dp,vector<bool>& vis,int &c){
    vis[in]=1;
    c++;
    for(int i=0;i<dp[in].size();i++){
        if(vis[dp[in][i]])
            continue;
        dfs(dp[in][i],dp,vis,c);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>());
    int k;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>k;
        dp[i].push_back(k);
        dp[k].push_back(i);
    }    
    vector<bool> vis(n);
    for(int i=0;i<n;i++){
        int c=0;
        if(!vis[i])
            dfs(i,dp,vis,c);
        res+=c/2;
    }
    cout<<res<<endl;
    return 0;
}
