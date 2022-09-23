#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int,bool> mp;
int base = 10000;

bool dfs(int k,vector<vector<int>>& nums,vector<int>& res,int& st){
    if(res[k]!=-1){
        st=k;
        return 1;
    }
    for(int i=0;i<nums[k].size();i++){
        res[k]=nums[k][i];
        bool f = dfs(nums[k][i],nums,res,st);
        if(f)
            return f;
        res[k]=-1;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> nums(base,vector<int>());
    int t;
    int v;
    int d;
    int Max = 0;
    for(int i=0;i<n;i++){
        cin>>t;
        cin>>v;
        if(Max<v)
                Max=v;
        for(int j=0;j<t-1;j++){
            cin>>d;
            if(Max<d)
                Max=d;
            nums[v-1].push_back(d-1);
        }
    }
    vector<int> res(Max,-1);
    vector<int> result;
    int start=0;
    for(int i=0;i<d;i++){
        bool f = dfs(i,nums,res,start);
        if(f)
            break;
    }
    int i = start;
    result.push_back(i);
    i=res[i];
    while(i!=result[0]){
        result.push_back(i);
        i = res[i];
    }
    result.push_back(i);
    int index = min_element(result.begin(),result.end())-result.begin();
    for(int k=0;k<result.size()-1;k++){
        cout<<result[index]+1<<" ";
        index=(index+1)%result.size();
    }
    cout<<result[index]+1<<endl;
    return 0;
}


// 3
// 3 1 2 5
// 3 2 3 4
// 2 3 1


// 3
// 6 1 2 3 4 5 6
// 5 2 3 4 5 6  
// 6 3 2 4 5 6 7