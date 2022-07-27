#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool mycompare(vector<int>& v1,vector<int>& v2){
    return v1[1]<v2[1];
}

vector<vector<int>> get(string& e){
    vector<vector<int>> res;
    int i=0;
    while(i<e.size()){
        bool f=1;
        int x=0;
        int y=0;
        if(e[i]=='+' || e[i]=='-'){
            if(e[i]=='-')
                f=1;
            i++;
        }
        while(i<e.size() && e[i]!='/'){
            x*=10;
            x+=(e[i]-'0');
            i++;
        }
        i++;
        while(i<e.size() && e[i]!='+' && e[i]!='-'){
            y*=10;
            y+=(e[i]-'0');
            i++;
        }
        if(f)
            res.push_back({x,y});
        else
            res.push_back({-x,y});
    }
    return res;
}

int get_diff(int x,int y){
    if(y==0)
        return x;
    return get_diff(y,x%y);
}

string fractionAddition(string e) {
    vector<vector<int>> nums = get(e);
    sort(nums.begin(),nums.end(),mycompare);
    string res = "";
    int x=nums[0][0];
    int y=nums[0][1];
    for(int i=1;i<nums.size();i++){
        int base = get_diff(y,nums[i][1]);
        x=(x*(nums[i][1]/base)+nums[i][0]*(y/base));
        y=y*nums[i][1]/base;
    }
    int base;
    if(abs(x)>y){
        base = get_diff(abs(x),y);
    }else
        base = get_diff(y,abs(x));
    x/=base;
    y/=base;
    if(x==0)
        y=1;
    res=to_string(x)+'/'+to_string(y);
    return res;
}

int main(int argc,char* argv[]){
    return 0;
}