#include <iostream>
#include <vector>

using namespace std;

bool juge(string& s1,string& s2){
    int r1=0;
    int r2=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='_')
            continue;
        r1*=10;
        r1+=(s1[i]-'0');
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='_')
            continue;
        r2*=10;
        r2+=(s2[i]-'0');
    }
    if(r1==0 || r2==0)
        return false;
    if(r1%r2==0 || r2%r1==0)
        return true;
    return false;
}

int dfs(string s1,string s2,int sum,int& res){
    if(juge(s1,s2)){
        if(sum<res){
            res=sum;
            // cout<<s1<<" "<<s2<<endl;
        }
        return 0;
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='_')
            continue;
        char t = s1[i];
        s1[i]='_';
        dfs(s1,s2,sum+1,res);
        s1[i]=t;
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='_')
            continue;
        char t = s2[i];
        s2[i]='_';
        dfs(s1,s2,sum+1,res);
        s2[i]=t;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string s1="55115549";
    string s2="15121982";
    int res=100000000;
    dfs(s1,s2,0,res);
    if(res==1000000000)
        cout<<-1<<endl;
    else
        cout<<res<<endl;
    return 0;
}
