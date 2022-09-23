#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
unordered_map<int,int> mp;
vector<int> get(int val){
    int v1,v2;
    v1 = sqrt(val);
    for(;v1>=1;v1--){
        if(val%v1==0)
            break;
    }
    v2 = val/v1;
    if(v1>=v2)
        return {v2,v1};
    return {v1,v2};
}
int juge(int val){
    if(val==1)
        return 0;
    if(val==2)
        return 1;
    vector<int> t = get(val);
    if(t[0]==1){
        return juge(val-1)+juge(1)+1;
    }
    return juge(t[0])+juge(t[1])+1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    
    int res = 0;
    for(int i=0;i<n;i++){
        if(mp.count(nums[i])){
            res+=mp[nums[i]];
            continue;
        }
        int val=juge(nums[i]);
        res+=val;
        mp[nums[i]]=val;
    }
    cout<<res<<endl;
    return 0;
}



