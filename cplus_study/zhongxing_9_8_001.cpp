#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int w[26]={0};
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.size();i++)
        w[s1[i]-'a']++;
    for(int i=0;i<s2.size();i++){
        if(w[s2[i]-'a']==0){
            cout<<s2[i]<<endl;
            break;
        }
    }
    return 0;
}
