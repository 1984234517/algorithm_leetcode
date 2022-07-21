#include <iostream>
#include <vector>

using namespace std;

string dfs(string& s,int l,int r){
    int st=-1;
    int e=-1;
    while(l>=0 && r<s.size()){
        if(s[l]!=s[r])
            break;
        st=l;
        e=r;
        l--;
        r++;
    }
    string res="";
    for(int i=st;i<=e && i>=0;i++)
        res.push_back(s[i]);
    return res;
}

string longestPalindrome(string s){
    string res="";
    for(int i=0;i<s.size();i++){
        string t1 = dfs(s,i,i);
        string t2 = dfs(s,i,i+1);
        if(t1.size()>t2.size()){
            if(res.size()<t1.size())
                res = t1;
        }else{
            if(res.size()<t2.size())
                res = t2;
        }
    }
    return res;
}