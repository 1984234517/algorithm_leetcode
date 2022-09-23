// 题目：给定一个数组里面的数是[0-9]，而且里面的数字不会重复，在给定一个limit
// 问用数组中的数组成小于limit的最大值
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int>& vis,int limit,int offset){
    if(offset==0)
        return limit;
    int cur = (limit/offset)%10;
    int index=0;
    while(index<vis.size() && vis[index]<=cur){
        index++;
    }
    index--;
    // 无法从vis中找到小于cur的数
    if(index==-1){
        return -1;
    }else if(vis[index]==cur){
        int ans = dfs(vis,limit,offset/10);
        if(ans != -1)
            return ans;
        if(index>0){
            ans = (limit/(offset*10))*10+vis[index-1];
            while(offset/10){
                ans*=10;
                ans+=vis[vis.size()-1];
                offset/=10;
            }
            return ans;
        }else{
            return -1;
        }
    }else{
        int ans = (limit/(offset*10))*10+vis[index];
        while(offset/10){
            ans*=10;
            ans+=vis[vis.size()-1];
            offset/=10;
        }
        return ans;
    }
}

int getRes(vector<int>& vis,int limit){
    // 首先得到一个位数和limit一样长的10的幂次方的数
    int offset = 1;
    limit--;
    int temp = limit;
    while(temp/10){
        offset*=10;
        temp/=10;
    }
    sort(vis.begin(),vis.end());
    // 尽量用vis中的数组合成一个接近limit-1的数，如果无法做到，返回-1
    int ans = dfs(vis,limit,offset);
    if(ans!=-1)
        return ans;
    // 去掉一位，其余位全部填充vis中的最大值
    ans = 0;
    while(offset/10){
        ans*=10;
        ans+=vis[vis.size()-1];
        offset/=10;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> vis = {2,5,8};
    int limit = 25522;
    cout<<getRes(vis,limit)<<endl;
    return 0;
}
