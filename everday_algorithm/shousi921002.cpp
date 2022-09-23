#include<iostream>
#include <queue>

using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){this->val = val;this->left=nullptr;this->right=nullptr;}
};
Node* getRes(Node* root){
    queue<Node*> qu;
    qu.push(root);
    Node* res = nullptr;
    while(qu.size()){
        int size = qu.size();
        for(int i=0;i<size;i++){
            Node* temp = qu.front();
            qu.pop();
            if(i==0)
                res = temp;
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    Node* l1 = new Node(2);
    Node* r1 = new Node(3);
    Node* r12 = new Node(4);
    Node* r22 = new Node(5);
    Node* root = new Node(1);
    r1->left = r12;
    r1->right = r22;
    root->left = l1;
    root->right = r1;
    auto res = getRes(root);
    cout<<res->val<<endl;
    return 0;
}
