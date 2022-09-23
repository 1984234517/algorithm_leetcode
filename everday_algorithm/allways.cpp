#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void exchange(vector<int>& nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void dfs(int index,vector<int>& nums){
    if(index==nums.size()){
        res.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++){
        // 如果当前的nums[i]和nums[i-1]相等，就表示，nums[i]这个数已经和index位置的数交换过一次了，
        // 如果再次交换，产生的全排列就会重复，所以针对这种情况我们直接跳过
        bool f=0;
        for(int j=index;j<i;j++){
            if(nums[j]==nums[i]){
                f=1;
                break;
            }
        }
        if(f)
            continue;
        exchange(nums,index,i);
        dfs(index+1,nums);
        exchange(nums,index,i);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    // sort(nums.begin(),nums.end());
    dfs(0,nums);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2};
    auto res = permuteUnique(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
