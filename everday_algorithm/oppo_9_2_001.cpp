#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_res(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int res=0;
    long long base=1;
    if(nums[n-1]==0)
        return res;
    for(int i=0;i<nums.size();i++){
        res+=nums[i]*base;
        base*=10;
    }
    return res;
}

int main(){
    vector<int> res = {0,4,0,0};
    cout<<get_res(res)<<endl;
    return 0;
}