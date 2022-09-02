#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct Node{
  long long val;
  int index;
  Node(long long val,int i){
    this->val=val;
    this->index=i;
  }
};

bool mycompare(Node* p1,Node* p2){
    return p1->val>p2->val;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> p(n);
  vector<int> s(n);
  vector<Node*> ss(n);
  unordered_map<int,bool> mp;
  long long res = 0;
  for(int i=0;i<n;i++)
    cin>>p[i];
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int i=0;i<n;i++){
    Node* k = new Node(s[i]*(100-p[i]),i);
    ss[i]=k;
  }
  sort(ss.begin(),ss.end(),mycompare);
  for(int i=0;i<m;i++){
    res+=(s[ss[i]->index]*100);
    mp[ss[i]->index]=1;
  }
  for(int i=0;i<n;i++){
      if(mp.count(i))
         continue;
      res+=p[i]*s[i];
  }
  double val= res/100.0;
  printf("%.2f\n",val);
  return 0;
}