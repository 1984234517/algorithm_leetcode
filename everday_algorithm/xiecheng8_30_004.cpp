#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
vector<int> s;

void dfs(int in,vector<unordered_set<int>>& dp,int& res,vector<bool>& vis){
    vis[in]=1;
    res|=s[in];
    if(res==7)
        return ;
    for(auto it:dp[in]){
        if(vis[it])
            continue;
        dfs(it,dp,res,vis);
        if(res==7)
            return ;
    }
}

int main()
{
    int n;
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='r')
            s.push_back(1);
        else if(c=='g')
            s.push_back(2);
        else
            s.push_back(4);
    }
    vector<unordered_set<int>> dp(n,unordered_set<int>());
    
    vector<vector<int>> nums(n-1,vector<int>());
    int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        dp[x-1].insert(y-1);
        dp[y-1].insert(x-1);
        nums[i]={x-1,y-1};
    }
    int res=0;
    
    for(int i=0;i<n-1;i++){
        x=nums[i][0];
        y=nums[i][1];
        dp[x].erase(y);
        dp[y].erase(x);
        vector<bool> vis(n);
        int v1=0;
        int v2=0;
        dfs(x,dp,v1,vis);
        dfs(y,dp,v2,vis);
        if(v1==v2 && v1==7)
            res++;
        dp[x].insert(y);
        dp[y].insert(x);
    }
    cout<<res<<endl;
    return 0;
}
