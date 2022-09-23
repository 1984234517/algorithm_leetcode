#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m,n,k,L;
    cin>>m>>n>>k>>L;
    // 构造接收数据(二维)
    vector<vector<int>> nums(m,vector<int>(n));
    // 构造卷积核
    vector<vector<int>> kear(k,vector<int>(L));
    // 构造结果数组(二维)
    vector<vector<int>> res(m,vector<int>(n));
    // 赋值
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<L;j++)
            cin>>kear[i][j];
    }
    // 构造输出结果
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum = 0;
            for(int t=max(0,i-k/2);t<=min(i+k/2,m-1);t++){
                for(int v=max(0,j-L/2);v<=min(j+L/2,n-1);v++){
                    sum+=nums[t][v]*kear[t-(i-k/2)][v-(j-L/2)];
                }
            }
            if(sum>255)
                res[i][j]=255;
            else if(sum<0)
                res[i][j]=0;
            else
                res[i][j]=sum;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++)
            cout<<res[i][j]<<" ";
        cout<<res[i][n-1]<<endl;
    }
    return 0;
}
