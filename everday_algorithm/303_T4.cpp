#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 303周赛T4
int cmput(int val){
    int res=0;
    while(val){
        res++;
        val&=(val-1);
    }
    return res;
}
// 思路：首先得明白一点就是，k1&k2=n1和k1|k2=n2，n1的二进制数中1的个数加上n2的二进制中1的个数
// 就等价于k1的二进制1的个数加上k2的二进制1的个数，明白这点后，整体思路就十分明朗了
// 因为选择的数对是可以重复的，所以我们先利用一个set来去重，然后对得到的set中的元素计算它们
// 二进制中1的个数，把他们添加到一个数组中，然后对这个数组排序
// 这样，题目要求的数对，就转换成了在这个数组寻找两个元素和大于等于k的数对个数
// 这样只需要遍历一遍这个数组固定一个数，然后再利用二分求一个满足要求的第二个点
long long countExcellentPairs(vector<int>& nums, int k) {
    int size=nums.size();
    unordered_set<int> st;
    for(int i=0;i<size;i++)
        st.insert(nums[i]);
    vector<int> cnt;
    for(auto it:st){
        cnt.push_back(cmput(it));
    }
    sort(cnt.begin(),cnt.end());
    long long res=0;
    size=cnt.size();

    for(auto it:cnt){
        auto itt = lower_bound(cnt.begin(),cnt.end(),k-it);
        res+=(0LL+size-(itt-cnt.begin()));
    }
    return res;
}