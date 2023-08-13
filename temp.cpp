#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node * first;
    Node(){
        this->data = 0;
        this->next = NULL;
        this->first = this;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        ListNode* current = first;
        ListNode* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    
}