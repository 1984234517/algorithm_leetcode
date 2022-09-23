#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<int>> nums(n,vector<int>(n,-1));
    int res = n*n;
    int odd=res/2+1,even=res/2;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            // 构造初始第一个点
            if(i==0 && j==0){
                nums[i][j]=1;
                nums[i+1][j]=1;
                nums[i][j+1]=1;
                nums[i+1][j+1]=0;
                odd-=3;
                even-=1;
                continue;
            }
            // 考虑以当前这个点为左上角的2*2阶矩阵和的奇偶性
            int cur_odd = 0;
            int cur_even = 0;
            // 考虑当前点
            if(nums[i][j]==0)
                cur_even++;
            else
                cur_odd++;
            // 考虑当前矩阵的左下点
            if(nums[i+1][j]==0)
                cur_even++;
            else if(nums[i+1][j]==1)
                cur_odd++;
            // 考虑当前矩阵的右上点
            if(nums[i][j+1]==0)
                cur_even++;
            else if(nums[i][j+1]==1)
                cur_odd++;
            // 判断，当前的2*2矩阵中奇数和偶数的个数情况
            // 当前奇数和偶数都是1，那么剩下的两个只能全选0或者1
            if(cur_even==1 && cur_odd==1){
                // 如果当前剩余的奇数多，先填充奇数，如果偶数多，填充偶数
                if(odd>=even){
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=1;
                        odd--;
                    }
                }else{
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=0;
                        even--;
                    }
                }
            }else if(cur_even>1){
                // 如果当前2*2矩阵中偶数个数大于1，并且奇数出现过一次，剩下未填充的均填充偶数
                if(cur_odd){
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=0;
                        even--;
                    }
                }else{
                    // 如果当前只有偶数个数出现大于1，但是奇数没有出现，把位置(i+1,j+1)设置为奇数，其它设置为偶数
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=0;
                        even--;
                    }
                }
            }else if(cur_odd>1){
                // 如果当前2*2矩阵中奇数个数大于1，并且偶数出现过一次，剩下未填充的均填充奇数
                if(cur_even){
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=1;
                        odd--;
                    }
                }else{
                    // 如果当前只有奇数个数出现大于1，但是偶数没有出现，把位置(i+1,j+1)设置为偶数，其它设置为奇数
                    if(nums[i][j+1]==-1){
                        nums[i][j+1]=1;
                        odd--;
                    }
                    if(nums[i+1][j+1]==-1){
                        nums[i+1][j+1]=0;
                        even--;
                    }
                    if(nums[i+1][j]==-1){
                        nums[i+1][j]=1;
                        odd--;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
