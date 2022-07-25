#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
bool dfs(TreeNode* head,queue<TreeNode*> &qu){
    queue<TreeNode*> qu1;
    qu1.push(head);
    bool f=0;
    while(qu1.size()){
        int size = qu1.size();
        for(int i=0;i<size;i++){
            auto it = qu1.front();
            qu1.pop();
            if(it->left)
                qu1.push(it->left);
            if(it->right)
                qu1.push(it->right);
            if(it->left==nullptr || it->right==nullptr){
                if(qu.size()==0){
                    if(it->left==nullptr)
                        f=1;
                }
                qu.push(it);
            }
        }
    }
    return f;
}
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> qu;
    bool type;
    
    CBTInserter(TreeNode* root1) {
        root=root1;
        type = dfs(root,qu);
        // cout<<qu.size()<<endl;
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* temp = qu.front();
        if(type){
            temp->left=newNode;
            type=0;
        }else{
            temp->right = newNode;
            qu.pop();
            type=1;
        }
        qu.push(newNode);
        return temp->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
