#include <iostream>
#include <vector>

using namespace std;

int get_res(string& s){
    vector<vector<int>> W(26,vector<int>(1,-1));
    int res = 0;
    int n=s.size();
    vector<int> P(26,-1);
    vector<int> C(26,0);
    for(int i=0;i<n;i++){
        if(P[s[i]-'A']==-1){
            C[s[i]-'A']=i-P[s[i]-'A'];
            P[s[i]-'A']=i;
        }else{
            res+=(C[s[i]-'A']*(i-P[s[i]-'A']));
            C[s[i]-'A']=i-P[s[i]-'A'];
            P[s[i]-'A']=i;
        }
    }
    for(int i=0;i<26;i++){
        if(P[i]!=-1){
            res+=(C[i]*(n-P[i]));
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "ABC";
    cout<<get_res(s)<<endl;
    return 0;
}








// 6 6
// SBBBBB
// BXXXXB
// BBXBBB
// XBBXXB
// BXBBXB
// BBXBEB
// 13

// 5 5
// SBBBB
// BBBBB
// BBBBB
// BBBBB
// BBBBE