#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& v1,vector<int>& v2){
//     if(v1[1]==v2[1])
//         return v1[0]<v2[0];
    return v1[0]<v2[0];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(2));
    int s,e;
    int maxV;
    for(int i=0;i<n;i++){
        scanf("%d,%d",&s,&e);
        dp[i][0]=s;
        dp[i][1]=e;
        if(maxV<e)
            maxV=e;
    }
    int res = 0;
    vector<int> nums(maxV+1);
    for(int i=0;i<n;i++){
        nums[dp[i][0]]+=1;
        nums[dp[i][1]+1]-=1;
    }
    int sum_ = 0;
    int count = 0;
    for(int i=1;i<=maxV;i++){
        sum_+=nums[i];
        if(sum_==1){
            count++;
        }else{
            if(count>1)
                res+=count+1;
            else
                res+=count;
            count=0;
        }
    }
    cout<<res<<endl;
    return 0;
}