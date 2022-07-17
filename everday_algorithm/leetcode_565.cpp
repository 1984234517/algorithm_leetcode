#include <iostream>
#include <vector>

using namespace std;

void dfs(int i,vector<int>& nums,vector<bool>& vis,int& count){
    count++;
    vis[i]=1;
    if(vis[nums[i]])
        return ;
    dfs(nums[i],nums,vis,count);
}

// dfs，这个题目实际上考的就是最大联通分量的节点数
// 因为nums中的元素不重复，所以每个节点的入度和出度都是1，因此会出现很多环，
// 题目要求的就是这些环中节点数最大的那个环

// 方法一，利用一个vis数组来标记已被访问过的节点，空间复杂度0(n)
// 方法二，利用nums数组，把所有访问过的节点值标记为n，空间复杂度为0(1)
int arrayNesting(vector<int>& nums) {
    int size=nums.size();
    vector<bool> vis(size,0);
    int res=0;
    for(int i=0;i<size;i++){
        if(!vis[i]){
            int count=0;
            dfs(i,nums,vis,count);
            if(count>res)
                res=count;
        }
    }
    return res;
}