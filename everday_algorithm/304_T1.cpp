#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 法一
    int minimumOperations(vector<int>& nums) {
        // 注意这个题目的含义，每次让整个数组中非零的元素减去一个x(x是一个不超过整个数组最小非零元素的值)
        // 其实这个题目求的是这个数组中非零元素的不重复元素的个数，因为这是最少的调整次数
        sort(nums.begin(),nums.end());
        int res=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 || nums[i]-temp==0)
                continue;
            temp=nums[i];
            res++;
        }
        return res;
    }

    // 法二
    int minimumOperations(vector<int>& nums) {
        // 注意这个题目的含义，每次让整个数组中非零的元素减去一个x(x是一个不超过整个数组最小非零元素的值)
        // 其实这个题目求的是这个数组中非零元素的不重复元素的个数，因为这是最少的调整次数
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
                st.insert(nums[i]);
        }
        return st.size();
    }
};

int main(){
    return 0;
}