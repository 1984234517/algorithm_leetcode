#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  vector<int> b(n);
  for(int i=0;i<n;i++)
    cin>>b[i];
  for(int i=0;i<m;i++)
    cin>>a[i];
  long long res = 0;
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
      auto it=lower_bound(a.begin(),a.end(),b[i]);
      if(it!=a.end())
        res+=*it;
      else{
          cout<<-1<<endl;
          return 0;
      }
  }
  cout<<res<<endl;
  return 0;
}