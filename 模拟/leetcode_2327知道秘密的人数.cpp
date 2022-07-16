#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<vector<int>> delayTime;
        queue<vector<int>> forgetTime;
        int res=1;
        int base=1000000007;
        int temp=0;
        delayTime.push({1+delay,1});
        forgetTime.push({1+forget,1});
        for(int i=1;i<=n;i++){
            if(i==forgetTime.front()[0]){
                temp-=forgetTime.front().at(1);
                if(temp<0)
                    temp+=base;
                res-=forgetTime.front().at(1);
                if(res<0)
                    res+=base;
                forgetTime.pop();
            }
            if(i==delayTime.front()[0]){
                temp+=delayTime.front()[1];
                temp%=base;
                delayTime.pop();
            }
            if(temp){
                forgetTime.push({i+forget,temp});
                delayTime.push({i+delay,temp});
            }
            res=(0LL+res+temp)%base;
        }
        return res;
    }