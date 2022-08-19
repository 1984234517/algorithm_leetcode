#include <iostream>
#include <vector>

using namespace std;

int get_res(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2));
    vector<int> val(n+2);
    val[0]=val[n+1]=1;
    for(int i=0;i<n;i++)
        val[i+1]=nums[i];
    // 需要倒着遍历i
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n+2;j++){
            for(int k=i+1;k<j;k++){
                int sum=val[k]*val[i]*val[j];
                dp[i][j]=max(dp[i][j],sum+dp[i][k]+dp[k][j]);
            }
        }
    }
    return dp[0][n+1];
}

int main(){
    vector<int> res = {3,1,5,8};
    cout<<get_res(res)<<endl;
    return 0;
}