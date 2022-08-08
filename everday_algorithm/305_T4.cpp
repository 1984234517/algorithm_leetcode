#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        // dp[i]表示以s[i]为结尾的理想字符串的最长长度
        vector<int> dp(n+1,0);
        // 用来记录s[i]之前的出现的字符的最后一次出现的位置
        unordered_map<char,int> mp;
        // 刚开始全初始化为0
        for(int i=0;i<26;i++){
            mp['a'+i]=0;
        }
        dp[0]=0;
        int res=0;
        // 挨个遍历s中的每个位置
        for(int i=1;i<=n;i++){
            int t = s[i-1]-'a';
            // 遍历s中0-i-1出现过的字符
            for(int j=0;j<26;j++){
                // 符合情况的就更新
                if(abs(t-j)<=k){
                    dp[i]=max(dp[i],dp[mp[j+'a']]+1);
                }
            }
            // 记录字符s[i]最后一次出现的位置
            mp[s[i-1]]=i;
            if(dp[i]>res)
                res=dp[i];
        }
        return res;
    }
};