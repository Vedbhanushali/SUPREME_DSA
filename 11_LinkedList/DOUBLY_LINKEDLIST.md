# Doubly Linked List

## Structure / class of Doubly linked list

```cpp
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        if(this->prev!=NULL){
            this->prev = NULL;
        }
        if(this->next!=NULL){
            this->next = NULL;
        }
    }
};
```

## print doubly linked list

```cpp
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}
```

## length of doubly linked list

```cpp
void findlength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp!=NULL){
        temp= temp->next;
        length++;
    }
    return length;
}
```

## Insert at head

```cpp
void insertAtHead(Node* &head,Node* &tail,int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->perv = newNode;
        head = newNode;
    }
}
```

## Insert at tail

```cpp
void insertAtTail(Node* &head,Node* tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
```

## Insert at position

```cpp
void insertAtPostion(Node *&head,Node* &tail,int data,int position){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    if(postion == 1){
        insertAtHead(head,tail,data);
        return;
    }
    int len = findlength(head);
    if(postion > len){
        insertAtTail(head,tail,data);
        return;
    }
    int i = 1;
    Node* prevNode = head;
    while(i<postion-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;

    newNode->prev = prevNode;
    newNode->next = currNode

    prevNode->next = newNode;
    currNode->prev = newNode;
}
```

## Delete node from position

```cpp
void deleteFromPos(Node* &head,Node* &tail,int position){
    if(head==NULL){
        cout<<"Cannot delete";
        return;
    }
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    int len = findlength(head);
    if(position > len){
        cout<<"can't delete";
        return;
    }
    if(postion == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    if(position == len){
        Node* temp = tail;
        tail = tail->prev;
        temp-> prev = NULL;
        tail->next = NULL;
        delte temp;
        return;
    }

    //delete from middle of linked list
    int i = 1;
    Node* left = head;
    while(i < position - 1){
        left =  left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;
    left->next =  right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
```
