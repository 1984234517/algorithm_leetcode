#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int get_res(vector<int>& nums){
    // 当nums中没有重复元素时，解决方案是简单的
    // 所以当nums中有重复元素时，我们应该将其转换为没有重复元素(如何转化)
    int res = 1;
    int n = nums.size();
    vector<int> n1 = nums;
    unordered_map<int,int> mp;
    sort(n1.begin(),n1.end());
    for(int i=0;i<n;i++){
        if(mp.count(n1[i]))
            continue;
        mp[n1[i]]=i;
    }
    // 转换技巧(因为有n个数，所以利用0-n-1个序号来替换nums中的数
    // 这样就不会出现重复的数，也就可以使用没有重复元素的解法)
    for(int i=0;i<n;i++){
        nums[i]=mp[nums[i]]++;
    }
    int temp = -1;
    for(int i=0;i<n;i++){
        if(temp==-1){
            temp = nums[i];
        }else{
            if(temp>=i){
                if(temp<nums[i])
                    temp=nums[i];
            }else{
                res++;
                temp = nums[i];
            }
        }
    }
    return res;
}

int main(){
    vector<int> res = {2,1,3,4,4};
    cout<<get_res(res)<<endl;
    return 0;
}