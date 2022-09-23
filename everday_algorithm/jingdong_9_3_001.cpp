#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int maxV = 0;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(maxV<nums[i])
            maxV = nums[i];
    }
    int res=0;
    for(auto i:nums){
        if(i!=maxV)
            res++;
    }
    cout<<res<<endl;
    return 0;
}
