#include <iostream>
#include <vector>
using namespace std;


string solve(string s, string t) {
    string res;
    if(s=="0" || t=="0")
        return "0";
    int m=s.size();
    int n=t.size();
    vector<int> num(m+n);
    for(int i=m-1;i>=0;i--){
    int x=s[i]-'0';
    for(int j=n-1;j>=0;j--){
        int y=t[j]-'0';
        num[i+j+1]+=x*y;
    }
    }
    for(int i=m+n-1;i>0;i--){
    num[i-1]+=num[i]/10;
    num[i]%=10;
    }
    int key = num[0]==0?1:0;
    while(key<m+n){
    res.push_back(num[key]);
    key++;
    }
    for(auto& c:res){
    c+='0';
    }
    return res;
}

int main(){
    cout<<solve("20","8");
    return 0;
}