#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int size=nums.size();
    vector<int> res(size,pivot);
    int i=0,j=size-1;
    int i_=0,j_=size-1;
    while(i<size || j>=0){
        while(i<size && nums[i]>=pivot){
            i++;
        }
        // 找到一个小于pivot的元素
        if(i<size){
            res[i_++]=nums[i++];
        }

        while(j>=0 && nums[j]<=pivot){
            j--;
        }
        // 找到一个大于pivot的元素
        if(j>=0){
            res[j_++]=nums[j--];
        }
    }
    return res;
}