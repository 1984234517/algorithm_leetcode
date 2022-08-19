#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ct(string& s){
    int t=0;
    int i=0;
    vector<int> res(2,0);
    while(i<s.size() && s[i]!=':'){
        t=0;
        while(i<s.size() && s[i]!=':'){
            t*=10;
            t+=s[i]-'0';
            i++;
        }
        res[0]=t;
        t=0;
        while(i<s.size()){
            t*=10;
            t+=s[i]-'0';
            i++;
        }
        res[1]=t;
    }
    return res;
}

bool my(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0])
        return v1[1]<v2[1];
    return v1[0]<v2[0];
}

// 主函

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        string res;
        cin>>res;
        nums[i]=ct(res);
    }
    sort(nums.begin(),nums.end(),[](vector<int>& v1,vector<int>& v2)->bool{
    if(v1[0]==v2[0])
        return v1[1]<v2[1];
    return v1[0]<v2[0]; });
    long long res = 100000000000;
    int temp=0;
    for(int i=0;i<n-1;i++){
        temp+=(nums[i+1][0]-nums[i][0])*60;
        temp+=(nums[i+1][1]-nums[i][1]);
        if(res>temp)
            res=temp;
    }
    temp=0;
    temp+=((nums[0][0]-nums[n-1][0]+24)%24)*60;
    temp+=(nums[0][1]-nums[n-1][1]);
    if(res>temp)
        res=temp;
    cout<<res<<endl;
    return 0;
}