#include <iostream>
#include <vector>

using namespace std;

struct Node{
    public:
        int key;
        int val;
        Node* next;
    Node(int key,int val,Node* next):key(key),val(val),next(next){}
    Node():key(-1),val(-1),next(nullptr){}
};

class HashMap{
    private:
        vector<Node*> map;
    public:
    HashMap(int size){
        map = vector<Node*>(size,new Node());
    }
    // 得到映射
    int getKeyVal(int key){
        return key%map.size();
    }
    // 添加值,如果key存在则修改原来key的值，否则新建
    bool setKey(int key,int val){
        Node* temp = map[getKeyVal(key)];
        while(temp->next && temp->key!=key){
            temp=temp->next;
        }
        if(temp->key==key)
            temp->val = val;
        else{
            Node* newNode = new Node(key,val,nullptr);
            temp->next = newNode;
        }
        return 1;
    }
    // 获取值,不存在返回-1
    int getKey(int key){
        Node* temp = map[getKeyVal(key)];
        while(temp && temp->key!=key)
            temp = temp->next;
        if(temp)
            return temp->val;
        else
            return -1;
    }
};

int main(int argc, char const *argv[])
{
    HashMap* p = new HashMap(23);
    p->setKey(2,34);
    p->setKey(6,34);
    p->setKey(7,34);
    p->setKey(7,33);
    p->setKey(8,34);
    cout<<p->getKey(7)<<endl;
    cout<<p->getKey(8)<<endl;
    cout<<p->getKey(2)<<endl;
    return 0;
}
