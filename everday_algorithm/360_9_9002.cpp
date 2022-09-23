#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int juge(string& s){
    int res=0;
    stack<int> st;
    int i=0;
    while(i<s.size()){
        string t = "";
        // 找数
        while(i<s.size() && s[i]!='*' && s[i]!='+'){
            t.push_back(s[i++]);
        }
        st.push(stoi(t));
        while(i<s.size() && s[i]=='*'){
            i++;
            t="";
            while(i<s.size() && s[i]!='*' && s[i]!='+'){
                t.push_back(s[i++]);
            }
            int val = st.top();
            st.pop();
            st.push(val*stoi(t));
        }
        i++;
    }
    while (st.size())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string s = "";
        cin>>s;
        // 判断一下是否成立
        string s1 = "";
        string s2 = "";
        int j=0;
        while(s[j]!='='){
            s1+=s[j++];
        }
        j++;
        while(j<s.size()){
            s2+=s[j++];
        }
        int v1 = juge(s1);
        int v2 = juge(s2);
        string te = "";
        if(v1==v2){
            cout<<"Yes"<<endl;
            continue;
        }else if(v1>v2){
            bool f=0;
            // 往v2中添加一个值
            for(int j=0;j<s2.size();j++){
                f=0;
                te+=s2[j];
                for(int k=0;k<10;k++){
                    string tt = te;
                    tt.push_back(('0'+k)); 
                    for(int t=j+1;t<s2.size();t++){
                        tt.push_back(s2[t]);
                    }
                    if(juge(tt)==v1){
                        cout<<"Yes"<<endl;
                        f=1;
                        break;
                    }
                }
                if(f)
                    break;
            }
            if(!f)
                cout<<"No"<<endl;
        }else{
            // 往v1中添加一个值
            bool f=0;
            for(int j=0;j<s1.size();j++){
                f=0;
                te+=s1[j];
                for(int k=0;k<10;k++){
                    string tt = te;
                    tt.push_back(('0'+k)); 
                    for(int t=j+1;t<s1.size();t++){
                        tt.push_back(s1[t]);
                    }
                    if(juge(tt)==v2){
                        cout<<"Yes"<<endl;
                        f=1;
                        break;
                    }
                }
                if(f)
                    break;
            }
            if(!f)
                cout<<"No"<<endl;
        }
    }
    return 0;
}
