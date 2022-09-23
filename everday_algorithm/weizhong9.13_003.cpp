#include <iostream>
#include <vector>

using namespace std;

int base = 998244353;
int n,m;

bool juge(vector<int>& vis){
  int n = vis.size();
  vector<int> dp(n,1);
  int res = 1;
  for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
      if(vis[i]>vis[j])
        dp[i]=max(dp[i],dp[j]+1);
      if(dp[i]>3)
        return 0;
      if(res<dp[i])
        res=dp[i];
    }
  }
  if(res==3)
    return 1;
  return 0;
}

bool juge2(vector<int>& vis){
    int n = vis.size();
    vector<int> dp;
    dp.push_back(vis[0]);
    for(int i=1;i<n;i++){
        int l=0,r=dp.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(dp[mid]>=vis[i])
                r = mid-1;
            else
                l = mid+1;
        }
        if(l<dp.size()){
            dp[l]=vis[i];
        }else
            dp.push_back(vis[i]);
        if(dp.size()>3)
            return 0;
    }
    if(dp.size()==3)
        return 1;
    return 0;
}

void dfs(int index,vector<int>&nums,int& res){
    if(index==n){
        if(juge2(nums)){
            res++;
        }
        return ;
    }
    for(int i=1;i<=m;i++){
        nums[index]=i;
        dfs(index+1,nums,res);
        nums[index]=0;
    }
}

int main(){
  cin>>n>>m;
  vector<int> nums(n);
  int res = 0;
  dfs(0,nums,res);
  cout<<res<<endl;
  return 0;
}