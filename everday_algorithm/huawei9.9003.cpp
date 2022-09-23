#include <iostream>
#include <vector>
using namespace std;

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int M,N,an,bn;

void dfs(int x,int y,vector<vector<int>>& dp,int& res,int a,int b,int c){
    if(c==0)
        return ;
    int val = juge(dp);
    if(val>res)
        res=val;
    // 选A
    for(int i=0;i<)
    // 选B
    // 都不选
}

int main()
{
    cin>>M>>N>>an>>bn;
    vector<vector<int>> dp(M,vector<int>(N));
    int res = 0;
    dfs(0,0,dp,res,an,bn,M*N);
    return 0;
}
