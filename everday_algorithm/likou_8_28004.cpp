#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> get(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
    int row=r.size();
    int col=c.size();
    vector<vector<int>> r_(k,vector<int>());
    vector<vector<int>> c_(k,vector<int>());
    vector<int> r_d(k);
    vector<int> c_d(k);
    queue<int> r_q;
    queue<int> c_q;
    vector<int> r_res(k);
    vector<int> c_res(k);
    for(int i=0;i<row;i++){
        r_[r[i][0]-1].push_back(r[i][1]-1);
        r_d[r[i][1]-1]++;
    }
    for(int i=0;i<col;i++){
        c_[c[i][0]-1].push_back(c[i][1]-1);
        c_d[c[i][1]-1]++;
    }
    for(int i=0;i<k;i++){
        if(r_d[i]==0)
            r_q.push(i);
        if(c_d[i]==0)
            c_q.push(i);
    }
    // 开始遍历列
    int cc = 0;
    while(c_q.size()){
        auto it = c_q.front();
        c_res[it]=cc++;
        c_q.pop();
        for(int i=0;i<c_[it].size();i++){
            c_d[c_[it][i]]--;
            if(c_d[c_[it][i]]==0)
                c_q.push(c_[it][i]);
        }
    }
    // 开始遍历列
    cc = 0;
    while(r_q.size()){
        auto it = r_q.front();
        r_res[it]=cc++;
        r_q.pop();
        for(int i=0;i<r_[it].size();i++){
            r_d[r_[it][i]]--;
            if(r_d[r_[it][i]]==0)
                r_q.push(r_[it][i]);
        }
    }
    vector<vector<int>> res(k,vector<int>(k));
    for(int i=0;i<k;i++){
        res[r_res[i]][c_res[i]]=i+1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> r={{1,2},{3,2}};
    vector<vector<int>> c={{2,1},{3,2}};
    auto it = get(3,r,c);
    return 0;
}
