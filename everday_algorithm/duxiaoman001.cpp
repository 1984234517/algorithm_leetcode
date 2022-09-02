#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,k;
    int res=0;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(int i=0;i<n;i++){
        int Max=0,Min=1000000004;
        for(int j=i;j<n;j++){
            if(Max<nums[j])
                Max=nums[j];
            if(Min>nums[j])
                Min=nums[j];
            if(Max==Min*k)
                res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
