#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> vis;
int res = 0;
void dfs(string& s,int p){
    if(vis.count(s) && p==0){
        vis[s]=1;
        res++;
        return ;
    }
    string temp;
    for(int i =0;i<4;i++){
        temp = s;
        if(i==0){
            for(int j=0;j<s.size();j++){
                if(temp[j]=='0')
                    temp[j]='1';
                else
                    temp[j]='0';
            }
        }else if(i==1){
            for(int j=0;j<s.size();j++){
                if(j%2==0){
                    if(temp[j]=='0')
                        temp[j]='1';
                    else
                        temp[j]='0';
                }
            }
        }else if(i==2){
            for(int j=0;j<s.size();j++){
                if(j%2){
                    if(temp[j]=='0')
                        temp[j]='1';
                    else
                        temp[j]='0';
                }
            }
        }else{
            for(int j=0;j<s.size();j++){
                if(j%3==1){
                    if(temp[j]=='0')
                        temp[j]='1';
                    else
                        temp[j]='0';
                }
            }
        }
        // if(vis.count(temp))
        //     continue;
        dfs(temp,p-1);
    }
}

int getRes(int n,int p){
    string s = "";
    for(int i=0;i<n;i++){
        s.push_back('0');
    }
    dfs(s,p);
    return res;
}

int main(){
    cout<<getRes(2,1)<<endl;
    return 0;
}