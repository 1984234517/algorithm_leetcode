#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    shared_ptr<int> p=make_shared<int>(23);
    
    int res=0;
    int size=plants.size();
    int i=0,j=size-1;
    int capA=capacityA,capB=capacityB;
    while(i<j){
        if(capA>=plants[i]){
            capA-=plants[i++];
        }else{
            // 如果浇灌当前花水不够，那么需要灌满再浇花
            capA=capacityA;
            res++;
            capA-=plants[i++];
        }
        if(capB>=plants[j]){
            capB-=plants[j--];
        }else{
            // 如果浇灌当前花水不够，那么需要灌满再浇花
            capB=capacityB;
            res++;
            capB-=plants[j--];
        }
    }
    // 如果A和B同时浇灌同一朵花，如果A B两个水桶持有的水最大值小于这朵花需要的水
    // 那么就需要重新装水
    if(i==j){
        if(max(capA,capB)<plants[i])
            res++;
    }
    return res;
}