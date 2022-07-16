#include <iostream>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    string res="";
    int j=0;
    for(int i=0;i<s.size();i++){
        if(j<spaces.size() && i==spaces[j]){
            res.push_back(' ');
            j++;
        }
        res.push_back(s[i]);
        cout<<res<<endl;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> spaces = {8,13,15};
    cout<<addSpaces("LeetcodeHelpsMeLearn",spaces)<<endl;
    return 0;
}
