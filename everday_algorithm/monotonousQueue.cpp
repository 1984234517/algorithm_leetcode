#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> getRes(vector<int>& vis,int k){
    int n = vis.size();
    vector<int> res(n-k+1);
    deque<int> qu;
    // 优先把前k个数添加到队列中
    for(int i=0;i<n;i++){
        while(qu.size() && qu.back()<vis[i]){
            qu.pop_back();
        }
        qu.push_back(vis[i]);
        if(i>=k)
            if(qu.front()==vis[i-k])
                qu.pop_front();
        if(i>=k-1)
            res[i-k+1]=qu.front();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,2,4,2,1,5};
    auto it = getRes(nums,3);
    for(auto i:it)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
