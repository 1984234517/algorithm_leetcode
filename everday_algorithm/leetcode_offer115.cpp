#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& s) {
    int size = nums.size();
    // 用来记录每个节点的入度
    vector<int> sizeN(size,0);
    // 邻接表，因为子序列列表可能会存在重复的边，所以这里用了set来判断
    vector<unordered_set<int>> dp(size,unordered_set<int>());
    // 用来存放入度为0的节点
    queue<int> qu;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s[i].size()-1;j++){
            if(!dp[s[i][j]-1].count(s[i][j+1]-1))
                sizeN[s[i][j+1]-1]++;
            dp[s[i][j]-1].insert(s[i][j+1]-1);
        }
    }
    for(int i=0;i<dp.size();i++){
        if(sizeN[i]==0)
            qu.push(i);
    }
    int count = 0;
    while(qu.size()){
        // 当我们的拓扑排序出现了多种可能时，那就表明我们的nums一定不是唯一可能的序列
        if(qu.size()!=1)
            return false;
        int target = qu.front();
        count++;
        qu.pop();
        for(auto it:dp[target]){
            sizeN[it]--;
            if(sizeN[it]==0)
                qu.push(it);
        }
    }
    // 如果得到的拓扑排序的节点数和总结点不一样，说明不存在这样的序列
    if(count != size)
        return false;
    return true;
}

int main(){
    return 0;
}