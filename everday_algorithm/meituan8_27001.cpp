#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int> mp;
string s;
int n,m;

void dfs(int in,int& res,string t){
    if(in==n){
        bool f=1;
        for(auto it:mp){
            if(it.second){
                f=0;
                break;
            }
        }
        if(f)
            res++;
        return ;
    }
    t.push_back(s[in]);
    if(mp.count(t) && mp[t]>0){
        mp[t]--;
        dfs(in+1,res,"");
        mp[t]++;
    }
    dfs(in+1,res,t);
}

int main(){
    int res=0;
    cin>>n>>m;
    cin>>s;
    vector<int> tt(m);
    for(int i=0;i<m;i++)
        cin>>tt[i];
    for(int i=0;i<m;i++){
        string ss;
        cin>>ss;
        mp[ss]++;
    }
    dfs(0,res,"");
    cout<<res<<endl;
    return 0;
}