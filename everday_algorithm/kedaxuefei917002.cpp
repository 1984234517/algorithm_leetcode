#include <iostream>
#include <vector>

using namespace std;
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
int m,n;

void dfs(int i,int j,vector<vector<int>>& s,vector<vector<int>>& e,vector<vector<bool>>& vis,int& c){
    vis[i][j] = 1;
    int x,y;
    // 初始遍历看一下当前点(i,j)周围周围点是否都是未修改的
    for(int k=0;k<4;k++){
        x = i+X[k];
        y = j+Y[k];
        if(x<0 || x>=m || y<0 || y>=n || vis[x][y] || s[x][y]!=e[x][y])
            continue;
        c++;
        dfs(x,y,s,e,vis,c);
    }
}

int main(int argc, char const *argv[])
{
    cin>>m>>n;
    vector<vector<int>> s(m,vector<int>(n));
    vector<vector<int>> e(m,vector<int>(n));
    vector<vector<bool>> vis(m,vector<bool>(n,0));
    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>s[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>e[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j] || s[i][j]!=e[i][j])
                continue;
            int count = 1;
            dfs(i,j,s,e,vis,count);
            if(res<count)
                res = count;
        }
    }
    cout<<res<<endl;
    return 0;
}


// 测试案例1
// 5 5
// 1 5 3 2 5
// 1 0 4 7 2
// 3 4 2 3 3
// 1 3 2 4 8
// 4 3 1 5 7
// 1 5 3 2 5
// 2 3 4 6 2
// 3 3 3 4 1
// 1 3 4 5 8
// 4 2 7 3 8
// 测试结果
// 7

// 测试案例2
// 7 7
// 1 1 1 0 1 1 0
// 1 0 1 1 1 1 1
// 1 1 0 0 0 1 1
// 1 1 1 0 1 0 1
// 1 0 1 1 1 1 0
// 1 0 1 0 0 1 0
// 1 0 0 0 0 0 1
// 1 0 0 1 1 0 0
// 1 0 0 0 0 0 1
// 1 0 1 0 0 1 0
// 0 1 1 1 1 0 1
// 1 0 0 0 1 1 0
// 0 1 0 1 1 0 0
// 1 0 0 0 0 0 1
// 测试结果
// 17

