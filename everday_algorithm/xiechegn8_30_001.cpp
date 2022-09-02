#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int juge(int k){
    string t = to_string(k);
    bool f=0;
    for(int i=t.size()-1;i>=0;i--){
        if((t[i]-'0')%2==0){
            char number = t[t.size()-1];
            t[t.size()-1]=t[i];
            t[i]=number;
            f=1;
            break;
        }
    }
    if(!f)
        return -1;
    return atoi(t.c_str());
}

int main()
{
    int n;
    cin>>n;
    vector<int> res(n);
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(int i=0;i<n;i++){
        if(nums[i]==0)
            res[i]=0;
        res[i]=juge(nums[i]);
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<endl;
    return 0;
}
