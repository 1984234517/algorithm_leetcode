#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
int N;

int dfs(int i,vector<int>& nums,int sum,int& max_val){
    if(i>N){
        if(max_val<sum)
            max_val=sum;
        return 0;
    }
    dfs(2*i,nums,sum+nums[i-1],max_val);
    dfs(2*i+1,nums,sum+nums[i-1],max_val);
}

int main(){
    int n;
    cin>>n;
    N=n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int max_val=0;
    dfs(1,nums,0,max_val);
    cout<<max_val<<endl;
    return 0;
}