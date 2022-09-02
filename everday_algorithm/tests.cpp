#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0])
        return v1[1]<v2[1];
    return v1[0]<v2[0];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>dp[i][0];
        cin>>dp[i][1];
        cin>>dp[i][2];
    }
    sort(dp.begin(),dp.end(),compare);
    int res=0;
    vector<vector<int>> dp2;
    int s=dp[0][0];
    int e=dp[0][1];
    int count=dp[0][2];
    for(int i=1;i<m;i++){
        if(e>dp[i][0] ){
            e=max(e,dp[i][1]);
            count+=dp[i][2];
        }else{
            dp2.push_back({s,e,count});
            s=dp[i][0];
            e=dp[i][1];
            count=dp[i][2];
        }
    }
    for(int i=0;i<dp2.size();i++){
        res+=min(dp2[i][2],dp2[i][1]-dp2[i][0]+1);
    }
    res+=(dp2[0][0]-1);
    res+=(n-dp2[dp2.size()-1][1]);
    for(int i=1;i<dp2.size();i++){
        res+=(dp[i][0]-dp[i-1][1]);
    }
    cout<<res<<endl;
    return 0;
}
