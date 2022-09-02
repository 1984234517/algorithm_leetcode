#include <iostream>
#include <vector>
#include <random>
using namespace std;

int n,m,k,x;

void dfs(int X,int Y,vector<vector<int>>& nums,int val,bool& res){
    if(X==n-1&& Y==m-1){
        val+=nums[X][Y];
        if(val==x)
            res=1;
        return ;
    }
    if(X+1<n)
        dfs(X+1,Y,nums,val+nums[X][Y],res);
    if(res)
        return ;
    if(Y+1<m)
        dfs(X,Y+1,nums,val+nums[X][Y],res);
}
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    vector<string> res(T,"no");
    for(int i=0;i<T;i++){
        cin>>n>>m>>k>>x;
        vector<vector<int>> nums(n,vector<int>(m));
        for(int j=0;j<n;j++){
            for(int t=0;t<m;t++){
                int val;
                cin>>val;
                if(val>0)
                    nums[j][t]=1;
                else
                    nums[j][t]=-1;
            }
        }
        if(x%k)
            continue;
        x/=k;  
        bool f=0;
        dfs(0,0,nums,0,f);
        if(f)
            res[i]="yes";
    }
    for(int i=0;i<T;i++)
        cout<<res[i]<<endl;
    return 0;
}
