#include <iostream>
#include <vector>
using namespace std;

bool compare(vector<int>& v1,vector<int>& v2){
    return v1[0]+v1[1]<v2[0]+v2[1];
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 得到最短路径长度
     * @param points int整型vector<vector<>> 食物位置
     * @return int整型
     */
    int getMinLen(vector<vector<int> >& p) {
        int res = 0;
        int n = p.size();
        int s=0;
        int e=0;
        for(int k=0;k<n;k++){
            int mi,val=-1;
            for(int i=0;i<n;i++){
                if(val==-1){
                    mi=i;
                    val = abs(p[mi][0]-s)+abs(p[mi][1]-e);
                    continue;
                }
                if(p[mi][0]==-1)
                    continue;
                if(abs(p[i][0]-s)+abs(p[i][1]-e)<val){
                    mi=i;
                    val = abs(p[mi][0]-s)+abs(p[mi][1]-e);
                }
            }
            res+=val;
            s=p[mi][0];
            e=p[mi][1];
            p[mi][0]=-1;
        }
        return res;
    }
};