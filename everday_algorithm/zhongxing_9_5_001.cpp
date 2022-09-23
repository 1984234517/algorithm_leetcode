#include <iostream>
#include <vector>

using namespace std;

int base = 5001;
int main()
{
    int p,q;
    cin>>p>>q;
    int temp;
    int k=0;
    vector<int> nums(base);
    vector<int> res(p);
    vector<int> s(q);
    for(int i=0;i<p;i++){
        cin>>temp;
        nums[temp]++;
    }
    for(int i=0;i<q;i++){
        cin>>temp;
        for(int j=0;j<nums[temp];j++)
            res[k++]=temp;
        nums[temp]=0;
    }
    for(int i=1;i<base;i++){
        for(int j=0;j<nums[i];j++)
            res[k++]=i;
    }
    for(int i=0;i<res.size()-1;i++)
        cout<<res[i]<<" ";
    cout<<res[res.size()-1]<<endl;
    return 0;
}
