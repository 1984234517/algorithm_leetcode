#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> res(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int val=i*col+j+k;
                int newX=(val/col)%row;
                int newY=val%col;
                res[newX][newY]=grid[i][j];
            }
        }
        return res;
    }
};