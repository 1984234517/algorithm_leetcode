#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double getRes(vector<int>& q,vector<int>& w,int k){
    priority_queue<int,vector<int>,less<int>> qu;
    int n = q.size();
    vector<int> nums(n);
    for(int i = 0;i < n;i++)
        nums[i]=i;
    sort(nums.begin(), nums.end(), [=](int i,int j)->bool{return w[i]*q[j]<=w[j]*q[i];});
    double ans = 0;
    int count = 0;
    for(int i = 0; i < k; i++){
        qu.push(q[nums[i]]);
        count+=q[nums[i]];
    }
    ans = count*(w[nums[k-1]]/(double)q[nums[k-1]]);
    // 开始遍历以每个工人的单位小时工资为基准
    for(int i=k;i<n;i++){
        if(qu.top()>q[nums[i]]){
            count -= qu.top();
            qu.pop();
            qu.push(q[nums[i]]);
            count += q[nums[i]];
        }
        if(ans>count*(w[nums[i]]/(double)q[nums[i]])){
            ans = count*(w[nums[i]]/(double)q[nums[i]]);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> q = {10,20,5};
    vector<int> w = {70,50,30};
    cout<<getRes(q,w,2);
    return 0;
}
