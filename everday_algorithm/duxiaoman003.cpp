#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int res=0;
    int base = 1000000007;
    vector<vector<int>> dp(n,vector<int>(9));
    for(int i=0;i<9;i++)
        dp[0][i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<9;j++){
            int val=0;
            if(j){
              for(int k=0;k<9;k++){
                val+=dp[i-1][k];
                val%=base;
              }
            }else{
                for(int k=1;k<9;k++){
                  val+=dp[i-1][k];
                  val%=base;
                }
                if(i>1){
                  val-=(dp[i-2][0]*8LL)%base;
                  if(val<0){
                    val=(val+base);
                  }
                }
              }
            dp[i][j]=val;
        }
    }
    for(int i=0;i<9;i++){
        res+=dp[n-1][i];
        res%=base;
    }
    cout<<res<<endl;
    return 0;
}
