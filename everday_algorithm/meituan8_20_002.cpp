#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> mp;
unordered_map<string,bool> mp1;
int n;

// 111
// 222
// 111

void compute(int dis,int a1,int a2,bool f){
    for(int i=0;i<=dis;i++){
      int x=a1+i;
      int y=a2+dis-i;
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(f)
            mp[s]=1;
          else
            mp1[s]=1;
      }
      x=a1+i;
      y=a2-(dis-i);
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(f)
            mp[s]=1;
          else
            mp1[s]=1;
      }
      x=a1-i;
      y=a2+dis-i;
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(f)
            mp[s]=1;
          else
            mp1[s]=1;
      }
      x=a1-i;
      y=a2-(dis-i);
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(f)
            mp[s]=1;
          else
            mp1[s]=1;
      }
  }
}

int main(){
    cin>>n;
    vector<int> a(6);
    vector<int> dis(n);
    int t;
    for(int i=0;i<6;i++){
        cin>>t;
        a[i]=t-1;
    }
    for(int i=0;i<n;i++)
        cin>>dis[i];
    vector<int> res(2,10000000);
    compute(dis[0],a[0],a[1],1);
    compute(dis[1],a[2],a[3],0);
    for(int i=0;i<=dis[2];i++){
      int x=a[4]+i;
      int y=a[5]+dis[2]-i;
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(mp.count(s) && mp1.count(s)){
              if((res[0]>x) || (res[0]==x && res[1]>y)){
                res[0]=x;
                res[1]=y;
              }
          }
      }
      x=a[4]+i;
      y=a[5]-(dis[2]-i);
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
          if(mp.count(s) && mp1.count(s)){
            if((res[0]>x) || (res[0]==x && res[1]>y)){
                res[0]=x;
                res[1]=y;
              }
          }
      }
      x=a[4]-i;
      y=a[5]+dis[2]-i;
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
                    if(mp.count(s) && mp1.count(s)){
              if((res[0]>x) || (res[0]==x && res[1]>y)){
                res[0]=x;
                res[1]=y;
              }
          }
      }
      x=a[4]-i;
      y=a[5]-(dis[2]-i);
      if(x>=0 && x<n && y>=0 && y<n){
          string s= to_string(x)+'_'+to_string(y);
            if(mp.count(s) && mp1.count(s)){
              if((res[0]>x) || (res[0]==x && res[1]>y)){
                res[0]=x;
                res[1]=y;
              }
          }
      }
  }
  cout<<res[0]+1<<" "<<res[1]+1<<endl;
  return 0;
}