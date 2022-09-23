#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    bool f;
    int count;
    TreeNode* son[26]; 
    TreeNode() : f(0),count(0){
        for(int i=0;i<26;i++)
            son[i]=nullptr;
    }
};

TreeNode* root = new TreeNode();

void buildTree(string& s){
    TreeNode* temp = root;
    for(int i=0;i<s.size();i++){
        if(temp->son[s[i]-'a']){
            temp->son[s[i]-'a']->count++;
            temp = temp->son[s[i]-'a'];
            continue;
        }
        TreeNode* t = new TreeNode();
        t->count=1;
        temp->son[s[i]-'a']=t;
        temp = t;
    }
    temp->f=1;
}

int query(string& s){
    TreeNode* temp = root;
    int sum = 0;
    for(int i=0;i<s.size();i++){
        if(temp->son[s[i]-'a']==nullptr)
            return 0;
        temp=temp->son[s[i]-'a'];
        sum+=temp->count;
    }
    return sum;
}


vector<int> sumPrefixScores(vector<string>& words) {
    int n = words.size();
    vector<int> res(n);
    for(int i=0;i<n;i++){
        buildTree(words[i]);
    }
    for(int i=0;i<n;i++){
        res[i]=query(words[i]);
    }
}


int main(int argc, char const *argv[])
{
    vector<string> vis = {"abcd"};
    auto res = sumPrefixScores(vis);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
