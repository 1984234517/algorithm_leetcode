#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<groupSizes.size();i++){
        mp[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> res;
    for(auto it:mp){
        vector<int> temp;
        for(int i=1;i<=it.second.size();i++){
            if(it.first==1 || i%it.first==1){
                res.push_back({});
            }else{
                res[res.size()-1].push_back(it.second[i]);
            }
        }
    }
    return res;
}

int main(){
    vector<int> res = {3,3,3,3,3,1,3};
    groupThePeople(res);
    return 0;
}