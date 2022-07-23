#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool juge(vector<int>& v1,vector<int>& v2,vector<int>& v3){
    long long s1=(v1[0]-v2[0])*(v1[0]-v2[0])+(v1[1]-v2[1])*(v1[1]-v2[1]);
    long long s2=(v1[0]-v3[0])*(v1[0]-v3[0])+(v1[1]-v3[1])*(v1[1]-v3[1]);
    long long s3=(v3[0]-v2[0])*(v3[0]-v2[0])+(v3[1]-v2[1])*(v3[1]-v2[1]);
    vector<long long> res;
    res.push_back(s1);
    res.push_back(s2);
    res.push_back(s3);
    sort(res.begin(),res.end());
    if(res[0]+res[1]==res[2])
        return true;
    return false;
}

int main(){
    int N;
    cin>>N;
    int res=0;
    vector<vector<int>> nums(N,vector<int>(2,0));
    for(int i=0;i<N;i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(juge(nums[i],nums[j],nums[k]))
                    res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}