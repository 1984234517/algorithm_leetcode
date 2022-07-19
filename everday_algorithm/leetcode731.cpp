#include <iostream>
#include <vector>

using namespace std;
class MyCalendarTwo {
public:
    // 用来存放单重的区间
    vector<vector<int>> booked;
    // 用来存放双重区间
    vector<vector<int>> doubleNum;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        //检查一下区间[start,end]和doubleNum中元素是否相交
        for(auto i:doubleNum){
            if(start<i[1] && end>i[0])
                return false;
        }
        // 检查区间[start,end]是否和book中的区间组成doubleNum中的元素
        for(auto i:booked){
            if(start<i[1] && end>i[0])
                doubleNum.push_back({max(i[0],start),min(i[1],end)});
        }
        booked.push_back({start,end});
        return true;
    }
};