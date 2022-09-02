#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int get_res(string& s,string& t){
    unordered_map<string,int> mp;
    int l1 = s.size();
    int l2 = t.size();
    int res=0;
    // 构建t字符串可以组成的所有连续字串，并利用mp保存下来
    for(int i=0;i<l2;i++){
        string temp = "";
        for(int j=i;j<l2;j++){
            temp.push_back(t[j]);
            mp[temp]++;
        }
    }
    // 遍历s字符串中可以组成的所有连续字串temp
    // 让temp中的每个字符都修改成另一个字符，判断是否在mp中出现过
    for(int i=0;i<l1;i++){
        string temp = "";
        for(int j=i;j<l1;j++){
            temp.push_back(s[j]);
            for(int k=0;k<temp.size();k++){
                char zim = temp[k];
                for(int c=0;c<26;c++){
                    if(c==temp[k]-'a')
                        continue;
                    temp[k]='a'+c;
                    if(mp.count(temp)){
                        res+=mp[temp];
                        temp[k]=zim;
                    }
                    temp[k]=zim;
                }
            }
        }
    }
    return res;
}

int main(){
    string s="abe";
    string t="bbc";
    cout<<get_res(s,t)<<endl;
    return 0;
}