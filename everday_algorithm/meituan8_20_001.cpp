#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(6);
  vector<int> dis(n);
  for(int i=0;i<6;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++)
    cin>>dis[i];
  vector<int> res(2);
  for(int i=max(0,max(a[0],max(a[2],a[4]))-max(dis[0],max(dis[1],dis[2])));i<n;i++){
    for(int j=max(0,max(a[1],max(a[3],a[5]))-max(dis[0],max(dis[1],dis[2])));j<n;j++){
      if(abs(a[0]-i)+abs(a[1]-j)!=dis[0])
        continue;
      if(abs(a[2]-i)+abs(a[3]-j)!=dis[1])
        continue;
      if(abs(a[4]-i)+abs(a[5]-j)!=dis[2])
        continue;
      cout<<i<<" "<<j<<endl;
      return 0;
    }
  }
    return 0;
}