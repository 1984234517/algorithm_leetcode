#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int s,vector<int>& nums,int aver,int pre){
    if(s==0)
        return true;
    for(int i=0;i<nums.size();i++){
        if(pre+nums[i]>aver)
            continue;
        if(s&(1<<i)){
            bool f = dfs(s^(1<<i),nums,aver,(pre+nums[i])%aver);
            if(f)
                return f;
        }
    }
    return false;
}

bool getRes(vector<int>& nums,int k){
    int n = nums.size();
    int sum = 0;
    for(int i=0;i<n;i++)
        sum+=nums[i];
    sort(nums.begin(),nums.end());
    if(sum%k || sum/k<nums[n-1])
        return false;
    return dfs((1<<n)-1,nums,sum/k,0);
}

int main(int argc, char const *argv[]) 
{
    vector<int> nums;
    int k = 6;
    cout<<getRes(nums,k)<<endl;
    return 0;
}
