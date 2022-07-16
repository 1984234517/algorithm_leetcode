#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 正序，只能应付没有nums中没有重复元素的情况
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations){
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]=i;
    for(auto val:operations){
        nums[mp[val[0]]]=val[1];
        mp[val[1]]=mp[val[0]];
        mp[val[0]]=-1;
    }
    return nums;
}

// 方法二，逆序，还可以应付nums中出现重复元素的情况
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations){
    unordered_map<int,int> mp;
    for(int i=operations.size()-1;i>=0;i--){
        if(mp.count(operations[i][1]))
            mp[operations[i][0]]=mp[operations[i][1]];
        else
            mp[operations[i][0]]=operations[i][1];
    }
    for(int i=0;i<nums.size();i++){
        if(mp.count(nums[i]))
            nums[i]=mp[nums[i]];
    }
    return nums;
}