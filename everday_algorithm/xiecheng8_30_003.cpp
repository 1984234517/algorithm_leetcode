#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int m;
    cin>>m;
    vector<int> nums(m);
    map<int,int,greater<int>> mp;
    for(int i=0;i<m;i++)
        cin>>nums[i];
    int val=0;
    for(int i=1;i<m;i++){
        mp[abs(nums[i]-nums[i-1])]++;
        val=max(val,abs(nums[i]-nums[i-1]));
    }
    for(int i=0;i<m;i++){
        if(i==0){
            mp[abs(nums[0]-nums[1])]--;
        }else if(i==m-1)
            mp[abs(nums[i-1]-nums[i])]--;
        else{
            mp[abs(nums[i]-nums[i-1])]--;
            mp[abs(nums[i]-nums[i+1])]--;
            mp[(abs(nums[i+1]-nums[i-1])+1)/2]++;
        }
        for(auto it:mp){
            if(it.second!=0){
                val=min(val,it.first);
                break;
            }
        }
        if(i==0){
            mp[abs(nums[0]-nums[1])]++;
        }else if(i==m-1)
            mp[abs(nums[i-1]-nums[i])]++;
        else{
            mp[abs(nums[i]-nums[i-1])]++;
            mp[abs(nums[i]-nums[i+1])]++;
            mp[(abs(nums[i+1]-nums[i-1])+1)/2]--;
        }
    }
    cout<<val<<endl;
    return 0;
}
