#include <iostream>
#include <vector>

using namespace std;

int get_res(int n){
    vector<int> dp(n);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main(){
    cout<<get_res(4)<<endl;
    return 0;
}