// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     string s="";
//     cin>>s;
//     int res=100000000;
//     int n=s.size();
//     string s1 = "r";
//     string s2 = "d";
//     int c=(n-1)/2;
//     for(int i=0;i<c;i++){
//         s1+='e';
//         if(i%2)
//             s1+='r';
//         else
//             s1+='d';
//     }
//     for(int i=0;i<c;i++){
//         s2+='e';
//         if(i%2)
//             s2+='d';
//         else
//             s2+='r';
//     }
//     cout<<s1<<endl;
//     cout<<s2<<endl;
//     c=0;
//     for(int i=0;i<s1.size();i++){
//         if(s[i]!=s1[i])
//             c++;
//     }
//     res=c;
//     c=0;
//     for(int i=0;i<s2.size();i++){
//         if(s[i]!=s2[i])
//             c++;
//     }
//     if(res>c)
//         res=c;
//     cout<<res<<endl;
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;
int get_res(int i1,int j1,vector<int>& v1,int i2,int j2,vector<int>& v2){
    int res = 0;
    for(int i=0;i<=(j1-i1);i++){
        if(v1[i+i1]!=v2[i+i2])
            res++;
    }
    return res;
}
int main(){
    string s="";
    cin>>s;
    int res=100000000;
    int n=s.size();
    // 1：0，2：0，3：1，4：1，5：2，6：2
    // 规律当长度n(n>2)为奇数时，合法的字符位置排列只有一个种情况0101010(1表示放e，0表示放其它的字符,
    // 所有的位置都必须按规定排放，没有不受约束的元素)
    // 规律当长度n(n>2)为偶数时，合法的字符位置排列种情况01010100,00101010,01010010，
    // 当中含有一个不受约束的元素。
    // dp[i][k],表示把s中前i个字符弄成合法e数目最多，但修改次数最少的情况,同时删除
    cout<<res<<endl;
    return 0;
}


