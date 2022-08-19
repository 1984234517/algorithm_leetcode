#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums;(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    long long res=0;
    for(int i=0;i<n-2;i++){
        unordered_map<int,int> mp;
        mp[3*nums[i+1]]=1;
        for(int j=i+2;j<n;j++){
            if(mp.count(nums[i]+nums[j]))
                res+=mp[nums[i]+nums[j]];
            mp[nums[j]*3]++;
        }
    }
    cout<<res<<endl;
    return 0;
}