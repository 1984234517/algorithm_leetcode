#include <iostream>
#include <vector>

using namespace std;

int dfs(int index,vector<bool>& vis,vector<vector<int>>& dp,int& res){
    vis[index]=1;
    int sum=1;
    for(int i=0;i<dp[index].size();i++){
        if(vis[dp[index][i]])
            continue;
        sum+=dfs(dp[index][i],vis,dp,res);
    }
    // 如果已经到达0点，就不需要计算了，否则需要计算需要多少辆车，每个车需要耗费一个单位的油
    if(index){
        if(sum%5)
            res++;
        res+=sum/5;
        cout<<"res="<<res<<endl;
    }
    return sum;
}

int get_res(vector<int>& A,vector<int>& B){
    int n=A.size();
    vector<vector<int>> dp(n+1,vector<int>());
    vector<bool> vis(n+1);
    for(int i=0;i<n;i++){
        dp[A[i]].push_back(B[i]);
        dp[B[i]].push_back(A[i]);
    }
    int res=0;
    dfs(0,vis,dp,res);
    return res;
}

int main(){
    vector<int> A{1,1,1,9,9,9,9,7,8};
    vector<int> B{2,0,3,1,6,5,4,0,0};
    cout<<get_res(A,B)<<endl;
    return 0;
}