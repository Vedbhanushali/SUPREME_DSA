# Linked List

## Single Linked list

```cpp
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

    void print(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp->next;
        }
    }   
}
```

## Find length of linkedList

```cpp
int findlength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len
}
```

## Insert at head

```cpp
void insertAtHead(Node* &head,Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
```

## Insert at tail

```cpp
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
```

## Insert at position

```cpp
void insertAtPostion(int data,int position,Node* &head,Node* &tail){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    if(postion == 0){
        insertAthead(head,tail,data);
        return;
    } 
    
    int len = findlength(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }

    int i=1;
    Node* prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newNode = newNode(data);
    newNode->next = curr;
    prev->next = newNode;
}
```

## Delete node at postion

```cpp
void deleteNode(int position, Node* &head,Node* &tail){
    if(head==NULL){
        cout<<"cannot delete";
        return;
    }

    if(postion == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findlength(head);
    if(postion > len){
        cout<<"cannot delete node";
        return;
    }
    int i = 1;
    Node* prev = head;
    while(i<postion-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
```

## Reverse linked list using loops

```cpp
Node* reverseUsingLoop(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
```

## Reverse linked list using recursion

```cpp
Node* reverseRE(Node* prev,Node* curr){
    //base case;
    if(curr == NULL){
        return prev;
    }
    
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    return reverseRE(prev,curr);
}
    //function call in main
    //Node* prev = NULL,
    //Node* curr = head;
    //head = reverseRE(prev,curr);
```
