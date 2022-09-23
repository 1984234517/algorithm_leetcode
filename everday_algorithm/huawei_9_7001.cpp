#include <iostream>
#include <vector>

using namespace std;

int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
int m,n;
int s1,s2,e1,e2;
void dfs(int s1,int s2,vector<vector<bool>>& vis,int val,int& res,int f){
    vis[s1][s2]=1;
    if(s1==e1 && s2==e2){
        if(val<res)
            res = val;
        vis[s1][s2]=0;
        return ;
    }
    for(int i=0;i<4;i++){
        int x=s1+X[i];
        int y=s2+Y[i];
        if(x<0 || x>=m || y<0 || y>=n || vis[x][y])
            continue;
        if(f==i)
            dfs(x,y,vis,val+1,res,i);
        else
            dfs(x,y,vis,val+2,res,i);
    }
    vis[s1][s2]=0;
}

int main()
{
    cin>>m>>n;
    vector<vector<bool>> vis(m,vector<bool>(n));
    char c;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='S'){
                s1=i;
                s2=j;
            }else if(c=='E'){
                e1=i;
                e2=j;
            }else if(c=='X'){
                vis[i][j]=1;
            }
        }
    }
    if(s1==e1 && s2==e2){
        cout<<0<<endl;
        return 0;
    }
    int res = 1000000007;
    for(int i=0;i<4;i++){
        int x=s1+X[i];
        int y=s2+Y[i];
        if(x<0 || x>=m || y<0 || y>=n || vis[x][y])
            continue;
        int temp=1000000007;
        dfs(x,y,vis,1,temp,i);
        res = min(res,temp);
    }
    if(res==1000000007)
        cout<<-1<<endl;
    else
        cout<<res<<endl;
    return 0;
}
