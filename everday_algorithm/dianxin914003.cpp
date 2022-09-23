#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v(m);
    vector<int> p(m);
    for(int i=0;i<m;i++)
        cin>>v[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>p[i];
    vector<vector<int>> dp(m,vector<int>(n+1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n+1;j++){
            if(i==0){
                if(j>=p[i])
                    dp[i][j]=v[i];
            }
            else{
                dp[i][j]=dp[i-1][j];
                if(j>=p[i]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-p[i]]+v[i]);
                }
            }
        }
    }
    cout<<dp[m-1][n]<<endl;
    return 0;
}