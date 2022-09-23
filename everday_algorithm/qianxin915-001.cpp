#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& v1,vector<int>& v2){
    return abs(v1[0]-v1[1])>abs(v2[0]-v2[1]);
}

void get(vector<int>& vis,string a){
    int i=0;
    string t;
    while(i<a.size()){
        t="";
        while(i<a.size() && a[i]!=','){
            t+=a[i];
            i++;
        }
        i++;
        vis.push_back(atoi(t.c_str()));
    }
}

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a;
    cin>>b;
    vector<int> A;
    vector<int> B;
    get(A,a);
    get(B,b);
    int res = 0;
    int n = A.size();
    vector<vector<int>> vis(n,vector<int>(2));
    for(int i=0;i<n;i++)
        vis[i]={A[i],B[i]};
    sort(vis.begin(),vis.end(),compare);
    int suma=0,sumb=0,minb=10000000;
    int ac=0,bc=0;
    for(int i=0;i<n;i++){
        if(vis[i][0]>vis[i][1] && (ac<2 || (ac==2 && (int)(suma+vis[i][0])*0.4<(vis[i][1]-vis[i][0])) || (ac>2 && (int)(vis[i][0])*0.4<(vis[i][1]-vis[i][0])))){
            sumb+=vis[i][1];
            if(minb>vis[i][1])
                minb=vis[i][1];
            bc++;
        }else{
            suma+=vis[i][0];
            ac++;
        }
    }
    if(ac>2){
        res+=(int)(suma*0.6);
    }else
        res+=suma;
    if(bc>2){
        sumb-=minb;
    }
    res+=sumb;
    cout<<res<<endl;
    return 0;
}
