#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int res=0;
    int n;
    cin>>n;
    vector<int> s(n);
    vector<int> e(n);
    vector<vector<int>> dp(n,vector<int>());
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            dp[s[i]-1].push_back(s[j]-1);
        }
    }
    for(int i=i;i<n;i++)
        cin>>e[i];
    unordered_map<int,bool> mp;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<dp[e[i]].size();j++){
            if(mp.count(dp[e[i]][j])){
                res++;
                break;
            }
        }
        mp[e[i]]=1;
    }
    cout<<res<<endl;
    return 0;
}
