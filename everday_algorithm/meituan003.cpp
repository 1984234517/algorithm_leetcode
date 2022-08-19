#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> res(n);
    int j=0;
    for(int i=0;i<n;i++){
        // 为当前的i寻找位置
        int count = 0;
        while(1){
            if(res[j]==0){
                count++;
                if(count==3)
                    break;
            }
            j=(j+1)%n;
        }
        res[j]=nums[i];
    }
    for(int i=0;i<n-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[n-1]<<endl;
    return 0;
}
