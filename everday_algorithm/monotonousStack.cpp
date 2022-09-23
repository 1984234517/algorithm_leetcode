#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单调栈
vector<int> getRes(vector<int>& vis){
    int n = vis.size();
    vector<int> res(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size() && vis[st.top()]<=vis[i]){
            st.pop();
        }
        if(st.size()){
            res[i]=st.top()-i;
        }
        st.push(i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,2,4,2,6,3};
    auto it = getRes(nums);
    for(auto i:it)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
