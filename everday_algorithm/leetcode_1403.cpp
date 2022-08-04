#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(2*temp>sum)
                break;
            temp+=nums[i];
            res.push_back(nums[i]);
        }
        return res;
    }
};

int main(){
    return 0;
}