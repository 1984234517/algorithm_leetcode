#include <iostream>
#include <vector>

using namespace std;
int getRes(string& s){
    vector<int> c(26,0);
    int l=0,r=0;
    int n = s.size();
    int res = 0;
    while(r<n){
        c[s[r]-'a']++;
        while(l<r && c[s[r]-'a']>1){
            c[s[l]-'a']--;
            l++;
        }
        r++;
        res = max(res,r-l);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    string s = "abcabcbb";
    cout<<getRes(s)<<endl;
    return 0;
}
