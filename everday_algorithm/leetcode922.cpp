#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val):val(val),next(nullptr){}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        Node* temp = head->next;
        while(index && temp){
            temp = temp->next;
            index--;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        temp->next->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0){
            addAtHead(val);
            return ;
        }
        if(index==size){
            addAtTail(val);
            return ;
        }else if(index<size){
            Node * temp = head;
            while(index){
                temp = temp->next;
                index--;
            }
            Node * newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size)
            return ;
        Node * temp = head;
        while(index){
            temp = temp->next;
            index--;
        }
        Node* node = temp->next;
        temp->next = temp->next->next;
        delete node;
        size--;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
