#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        nums[val-1]=i+1;
    }
    for(int i=1;i<n;i++)
        nums[i]=max(nums[i-1],nums[i]);
    for(int i=0;i<n-1;i++)
        cout<<nums[i]<<" ";
    cout<<nums[n-1]<<endl;
    return 0;
}