#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> juge(int a){
  vector<int> res;
  while(a){
    res.push_back(a%2);
    a/=2;
  }
  reverse(res.begin(),res.end());
  return res;
}

int dfs(int a,int b){
  vector<int> a1=juge(a);
  vector<int> a2=juge(b);
  int o1 = 0,o2=0;
  for(int i=0;i<a1.size();i++){
    if(a1[i]==1)
      o1++;
  }
  for(int i=0;i<a2.size();i++){
    if(a2[i]==1)
      o2++;
  }
  if(o1!=o2)
    return -1;
  for(int i=0;i<min(a1.size(),a2.size());i++){
    if(a1[i]!=a2[i])
      return -1;
  }
  int k = a1.size()-a2.size();
  if(k==0)
    return 0;
  else
    return k/3+1;
}

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int a,b;
    cin>>a>>b;
    if(a>b)
      cout<<dfs(a,b)<<endl;
    else
      cout<<dfs(b,a)<<endl;
  }
  return 0;
}