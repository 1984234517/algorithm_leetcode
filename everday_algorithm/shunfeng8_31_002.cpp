#include <iostream>
#include <vector>
int Max =  -1000000004;
int Min = 1000000004;

using namespace std;


int dfs(int k,vector<vector<int>>& dp,int& res,vector<int>& val){
    int minV=Min,maxV=Max;
    for(int i=0;i<dp[k].size();i++){
        int v = dfs(dp[k][i],dp,res,val);
        if(v>maxV)
            maxV=v;
        if(v<minV)
            minV=v;
    }
    // 没有孩子节点
    if(minV==Min && maxV==Max){
        return val[k];
    }
    // 只有一个孩子节点
    if(minV==Min)
        minV=0;
    if(Max==maxV)
        maxV=0;
    // 都为正
    if(minV>=0 && maxV>=0){
        res+=max(minV,maxV);
        return val[k]-max(minV,maxV);
    }
    // 都为负
    if(minV<=0 && maxV<=0){
        res+=abs(min(minV,maxV));
        return val[k]-min(minV,maxV);
    }
    // 一正一负
    res+=abs(minV)+abs(maxV);
    return val[k]-maxV-minV;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>> dp(n);
    vector<int> val(n);
    for(int i=1;i<n;i++){
        int k;
        cin>>k;
        dp[k-1].push_back(i);
    }
    for(int i=0;i<n;i++)
        cin>>val[i];
    int res=0;
    int tt = dfs(0,dp,res,val);
    cout<<res+tt<<endl;
    return 0;
}
