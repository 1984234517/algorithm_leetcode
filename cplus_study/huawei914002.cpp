#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> P(n);
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++)
        cin>>P[i];
    vector<vector<int>> data(n,vector<int>(2));
    for(int i=0;i<m;i++){
        cin>>data[i][0];
    }
    for(int i=0;i<m;i++){
        cin>>data[i][1];
    }
    
    return 0;
}