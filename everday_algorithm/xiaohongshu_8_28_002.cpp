#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long long k;
    cin>>n>>k;
    long long res=0;
    vector<long long> dp(n);
    for(int i=0;i<n;i++)
        cin>>dp[i];
    sort(dp.begin(),dp.end());
    for(int i=0;i<n;i++){
        long long cha=k/dp[i];
        if(k%dp[i])
          cha++;
        res += dp.end()-lower_bound(dp.begin(),dp.end(),cha);
        // 判断一下是否把自己也算进去了，因为双手不能施展两个相同的法术
        if(dp[i]*dp[i]>=k)
          res--;
    }
    cout<<res<<endl;
    return 0;
}