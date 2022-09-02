#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
};

ListNode* get_res(ListNode* n1,ListNode* n2){
    map<int,vector<ListNode*>> mp;
    ListNode* p1 = n1;
    ListNode* p2 = n2;
    while(p1){
        mp[p1->val].push_back(p1);
        p1 = p1->next;
    }
    while(p2){
        mp[p2->val].push_back(p2);
        p2 = p2->next;
    }
    ListNode* root=new ListNode(-1);
    p1 = root;
    for(auto it:mp){
        for(int i=0;i<it.second.size();i++){
            root->next = it.second[i];
            root = root->next;
        }
    }
    root->next = nullptr;
    return p1->next;
}

int main(){
    ListNode* n1 = new ListNode(3);
    ListNode* n12 = new ListNode(4);
    ListNode* n13 = new ListNode(1);
    n1->next = n12;
    n12->next = n13;

    ListNode* n2 = new ListNode(5);
    ListNode* n22 = new ListNode(6);
    ListNode* n23 = new ListNode(2);
    n2->next = n22;
    n22->next = n23;

    ListNode* temp = get_res(n1,n2);
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }
    return 0;
}