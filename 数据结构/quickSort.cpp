#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int quickSort(vector<int>& nums,int l,int r){
    int val = nums[l];
    int i=l;
    int j=r;
    while(i<j){
        while(i<j && nums[j]>=val)
            j--;
        nums[i]=nums[j];
        while(i<j && nums[i]<=val)
            i++;
        nums[j]=nums[i];
    }
    nums[i]=val;
    return i;
}

void sortQuick(vector<int>& nums,int l,int r){
    if(l>=r)
        return ; 
    int index = quickSort(nums,l,r);
    sortQuick(nums,l,index-1);
    sortQuick(nums,index+1,r);
}

int main(){
    vector<int> nums = {1,4,2,9,3};
    // 为了防止出现最差情况，先随机打乱排序
    random_shuffle(nums.begin(),nums.end());
    sortQuick(nums,0,nums.size()-1);
    for(auto i:nums)
        cout<<i<<endl;
    return 0;
}