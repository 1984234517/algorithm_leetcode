#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    map<int,int> mp;
    bool juge(int len,map<int,int>::iterator val){
        if(len==0)
            return 1;
        while(val!=mp.end() && !val->second)
            val++;
        if(val==mp.end())
            return 1;
        auto it=val->first;
        // 去掉两个相等的元素
        if(mp[it]>=2){
            mp[it]-=2;
            bool f = juge(len-2,val);
            mp[it]+=2;
            if(f)
                return f;
        }
        // 去掉三个相等的元素
        if(mp[it]>=3){
            mp[it]-=3;
            bool f = juge(len-3,val);
            mp[it]+=3;
            if(f)
                return f;
        }
        // 去掉3个连续的元素
        if(mp.count(it) && mp.count(it+1) && mp.count(it+2) && mp[it] && mp[it+1] && mp[it+2]){
            mp[it]--;
            mp[it+1]--;
            mp[it+2]--;
            bool f = juge(len-3,val);
            mp[it]++;
            mp[it+1]++;
            mp[it+2]++;
            if(f)
                return 1;
        }
        return 0;
    }
    bool validPartition(vector<int>& nums) {

        // 方法一，适用于随意划分，而不一定要求是子数组划分，此数据规模下超时
        // for(int i=0;i<nums.size();i++)
        //     mp[nums[i]]++;
        // return juge(nums.size(),mp.begin());

        // 方法二
        // 注意题目要求的是子数组，并不是可以随意划分
        int n = nums.size();
        vector<bool> f(n+1,0);
        f[0] = true;
        for (int i = 1; i < n; ++i)
            if (f[i - 1] && nums[i] == nums[i - 1] ||
                i > 1 && f[i - 2] && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
                                      nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))
                f[i + 1] = true;
        return f[n];
    }
};