#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int res = 0;
    int n=s.size();
    for(int i=0;i<n;i++){
        int result = 0;
        int left = 0;
        for(int j=i;j<n;j++){
            if(s[j]=='(')
                left++;
            else{
                if(left){
                    result++;
                    left--;
                }
            }
            res+=result;
        }
    }
    cout<<res*2<<endl;
    return 0;
}
