#include <iostream>
#include <vector>

using namespace std;

int base = 70001;

int juge(int k){
    int res = 0;
    while (k)
    {
        res^=(k%10);
        k/=10;
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    vector<int> l(T);
    vector<int> r(T);
    vector<int> t(T);
    vector<int> res(T);
    for(int i=0;i<T;i++)
        cin>>l[i];
    for(int i=0;i<T;i++)
        cin>>r[i];
    for(int i=0;i<T;i++)
        cin>>t[i];
    vector<vector<int>> dp(16,vector<int>());
    for(int i=0;i<base;i++)
        dp[juge(i)].push_back(i);
    for(int i=0;i<T;i++){
        auto it1 = lower_bound(dp[t[i]].begin(),dp[t[i]].end(),l[i]);
        auto it2 = lower_bound(dp[t[i]].begin(),dp[t[i]].end(),r[i]+1);
        res[i] = it2-it1;
    }
    for(int i=0;i<T-1;i++)
        cout<<res[i]<<" ";
    cout<<res[T-1]<<endl;
    return 0;
}
