#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>


using namespace std;

vector<int> a;
vector<int> b;
unordered_map<string,int> mp;
int n,m;
// dp[i1][j1][i2][j2]
long long dfs(int i1,int j1,int i2,int j2){
    string s=to_string(i1)+to_string(j1)+to_string(i2)+to_string(j2);
    if(mp.count(s))
        return mp[s];
    if(i1==j1){
        long long res=0;
        for(int i=i2;i<j2;i++)
            res+=abs(b[i]);
        mp[s]=res;
        return res;
    }
    if(i2==j2){
        long long res=0;
        for(int i=i1;i<j1;i++)
            res+=abs(a[i]);
        mp[s]=res;
        return res;
    }
    long long res=0;
    
    if(a[i1]==b[i2]){
        res =dfs(i1+1,j1,i2+1,j2);
    }else{
        res = min(dfs(i1+1,j1,i2+1,j2)+abs(a[i1]-b[i2]),min(dfs(i1+1,j1,i2,j2)+abs(a[i1]),dfs(i1,j1,i2+1,j2)+abs(b[i2])));
    }
    mp[s]=res;
    return res;
}

int main(){
  cin>>n>>m;
  a.resize(n);
  b.resize(m);
  vector<vector<int>> dp();
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<m;i++)
    cin>>b[i];
  long long res=0;
  cout<<dfs(0,n,0,m)<<endl;
  return 0;
}