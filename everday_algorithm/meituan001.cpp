#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 方法一
int main()
{
    int n,t;
    cin>>n>>t;
    vector<long long> nums(n);
    int res=0;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    long long temp=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(temp+t<=nums[i]){
            temp+=t;
        }else
            res++;
    }
    cout<<res<<endl;
    return 0;
}

// 方法二
int main()
{
    int n,t;
    cin>>n>>t;
    vector<long long> nums(n);
    int res=1;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    long long temp=t;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(temp<nums[i]){
            res++;
            temp=temp+t;
        }
    }
    cout<<n-res<<endl;
    return 0;
}
