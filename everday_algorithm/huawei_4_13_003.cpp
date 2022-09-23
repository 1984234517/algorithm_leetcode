#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    if(sum%2){
        cout<<-1<<endl;
        return 0;
    }
    int aver = sum/2;
    vector<vector<bool>> dp(n,vector<bool>(aver+1));
    dp[0][0]=1;
    dp[0][nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=aver;j++){
            if(dp[i-1][j])
                dp[i][j]=dp[i-1][j];
            else if(j>=nums[i] && dp[i-1][j-nums[i]]){
                dp[i][j] = dp[i-1][j-nums[i]];
            }
        }
    }
    // 不能从中利用某几个数得到aver
    if(!dp[n-1][aver]){
        cout<<-1<<endl;
        return 0;
    }
    cout<<aver<<endl;
    vector<bool> vis(n);
    vector<int> res;
    int s=n-1,e=aver;
    while(s>=0){
        if(e>=nums[s] && dp[s][e-nums[s]]){
            res.push_back(s);
            e -= nums[s];
            vis[s]=1;
        }
        s--;
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size()-1;i++)
        cout<<nums[res[i]]<<" ";
    cout<<nums[res[res.size()-1]]<<endl;
    res.clear();
    for(int i=0;i<n;i++){
        if(!vis[i])
            res.push_back(i);
    }
    for(int i=0;i<res.size()-1;i++)
        cout<<nums[res[i]]<<" ";
    cout<<nums[res[res.size()-1]]<<endl;
   return 0;
}