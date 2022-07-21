#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // 遍历到空节点直接返回
        if(root==nullptr)
            return root;
        // 如果左孩子返回空，表示该树的左子树为空或者没有值为1的节点
        root->left=pruneTree(root->left);
        // 如果右孩子返回空，表示该树的右子树为空或者没有值为1的节点
        root->right=pruneTree(root->right);
        // 如果该节点的左右孩子为空，或者没有值为1的节点，并且该节点的值本身为0
        // 直接返回nullptr;
        if(root->left || root->right || root->val)
            return root;
        return nullptr;
    }
};