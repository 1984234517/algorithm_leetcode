#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    string s;
    cin>>s;
    int x=0,y=0;
    int count = n*m-1;
    vis[0][0]=1;
    for(int i=0;i<k;i++){
        if(s[i]=='W'){
            x--;
        }else if(s[i]=='S')
            x++;
        else if(s[i]=='A')
            y--;
        else
            y++;
        if(!vis[x][y]){
            count--;
            if(count==0){
                cout<<"YES"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
            vis[x][y]=1;
        }
    }
    cout<<"NO"<<endl;
    cout<<count<<endl;
    return 0;
}