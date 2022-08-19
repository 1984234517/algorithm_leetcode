#include <vector>
#include <iostream>

using namespace std;

int get_res(vector<int>& nums,int x,int y){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(x+1,1000000000));
    int res = 1000000000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x && j<=i;j++){
            if(j==1)
                dp[i][j]=min(dp[i-1][j],nums[i-1]);
            else{
                if(i-y>=0){
                    dp[i][j]=min(dp[i-1][j],dp[i-y][j-1]+nums[i-1]);
                }else
                    dp[i][j]=dp[i-1][j];
            }
            if(j==x && res>dp[i][j])
                res=dp[i][j];
        }
    }
    return res;
}



int get(vector<int>& nums,int x,int y){
    int res = 100000000;
    for(int i=0;i<nums.size();i++){
        if(i+y*(x-1)>=nums.size())
            break;
        int total = 0;
        for(int j=0;j<x;j++){
            total+=nums[i+j*y];
        }
        if(total<res)
            res=total;
    }
    return res;
}

int main(){
    // vector<int> res={4,2,5,4,3,5,6,1,4,2,7};
    vector<int> res={4,2,5,4,3,5,1,4,2,7};
    cout<<get_res(res,3,2)<<endl;
    cout<<get(res,3,2);
    return 0;
}