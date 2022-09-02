#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0])
        return v1[1]<v2[1];
    return v1[0]>v2[0];
}

int main(){
    int n,m,id;
    cin>>n>>m>>id;
    vector<vector<int>> im(n,vector<int>(2));
    for(int i=0;i<n;i++){
        int sum = 0;
        int t=0;
        for(int j=0;j<m;j++){
            cin>>t;
            sum+=t;
        }
        im[i]={sum,i};
    }
    sort(im.begin(),im.end(),compare);
    for(int i=0;i<n;i++){
        if(im[i][1]==id-1){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}