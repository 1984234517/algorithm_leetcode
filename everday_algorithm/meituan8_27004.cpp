#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,b;
int main(){
    cin>>n>>b;
    vector<int> p(n);
    vector<int> t(n);
    priority_queue<int,vector<int>, greater<int>> pt;
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    int res=100000000;
    if(p[0]>b){
        cout<<-1<<endl;
        return 0;
    }
    b-=p[0];
    res+=t[0];
    pt.push(t[1]);
    for(int i=1;i<n;i++){
        if(t[i]<pt.top() && b>=p[i]){
            pt.push(t[i]);
            b-=p[i];
        }
        res=;
    }
    cout<<res<<endl;
    return 0;
}