#include <iostream>
#include <vector>

using namespace std;

int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    // 首先把所有需要挖取的网格位置保存起来
    for(auto val:dig)
        vis[val[0]][val[1]]=1;
    int res=0;
    // 遍历所有的artifacts，看哪些工件可以完全挖取出来
    for(auto val:artifacts){
        bool f=1;
        for(int x=val[0];x<=val[2];x++){
            for(int y=val[1];y<=val[3];y++){
                if(!vis[x][y]){
                    f=0;
                    break;
                }
            }
        }
        if(f)
            res++;
    }
    return res;
}