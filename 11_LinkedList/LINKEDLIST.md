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

## Find middle of Linked list

```cpp
Node* getMiddle(Node* head){
    if(head==NULL){
        cout<<"LL is empty";<<endl;
        return head;
    }
    if(head->next == NULL){
        //only one node in LL
        return head;
    }
    //LL have more than 1 node
    Node* slow = head;
    Node* fast = head; // for even case based on middle element tweak this 
    // Node* fast = head->next; or above
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
//function call
cout<<"middle node is"<<(head ? getMiddle(head)->data : "empty");
```

## K groups reverse linked list

example 10-20-30-40-50-60 and k = 3  
output = 30-20-10-60-50-40

10-20-30-40-50 k = 3  
output - 30-20-10-50-40

```cpp
int getLength(Node* head){
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
Node* reverseKNodes(Node *head,int k){
    if(head==NULL) return head; //LL is empty
    int len = getLength(head);
    if(k>len){
        return head; // no need of reversing LL is small as compared to k
    }

    //reverse first k noded of LL;
    Node * prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count<k){
        forward = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    //recursive call
    if(forward!=NULL){
        //we still have nodes to reverse
        head->next = reverseKNodes(forward,k)
    }
    //return head of the linked list
    return prev;
}
```

## Is LL circular / Detect and delete loop

Variations

- check loops is present
- starting point of loop
- remove loop

Approach

- can be solved using maps storing node address as key and value as boolean (true for visited)
- floyd cycle detection (slow fast pointer approach)
  - (sloww == fast) - loop present
  - (fast == NULL) - loop not present

```cpp
// FCD
bool checkForLoop(Node* &head){
    if(head==NULL) return false;

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) return true; //loop present
    }
    return false; //loop not present
}
```

find starting point of loop

- slow or fast meet that address
- make slow = head and move both slow one node and fast one node when then will meet that point is answer

```cpp
Node* startingPoint(Node* &head){
    if(head==NULL) return head;

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            slow = head;
            break;
        }
    }
    if(fast==NULL) return head; // if no loop then return head
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow; 
}
```

Removing loop

```cpp
Node* removeLoop(Node* &head){
    if(head==NULL) return head;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            slow = head;
            prev = fast;
            break;
        }
    }
    if(fast==NULL) return head; // if no loop then return head
    while(slow!=fast){
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow; 
}
```

## Linked list is palindrome or not

### approach

1. create a new linked list reverse of original  
compare both of them if same then it is palindrome else not
2. create a array from linked list and find palindrome from two pointer approach
3. reverse linked list after middle node and attach head after middle node , from that node compare first node one by one till second node reaches null.

```cpp
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
bool checkPalindrome(Node* &head){
    if(head==NULL) return true; //if empty return true
    if(head->next==NULL) return true; // only one node so palindrome

    // node > 1
    Node* slow = NULL;
    Node* fast = NULL;
    while(fast!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //slow is pointing to mid
    // reverse linked list after middle node
    Node* reverseLLkaHead = reverse(slow->next);
    slow->next = reverseLLKaHead;

    // start comparison
    Node* temp1 = head;
    Node* temp2 = slow->next; // or reverseLLKaHead
    while(temp2!=NULL){
        if(temp1->data!=temp2->data) return false; // not a palindrome
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
```

## Remove duplicates from a sorted LL

```cpp
void removeDuplicates(Node* head){
    if(head==NULL) return head;
    if(head->next==NULL) return head;

    //node > 1

    Node* curr = head;
    while(curr!=NULL){
        if((curr->next!=NULL) && (curr->data == curr->next->data)){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            //delete node
            temp->next = NULL;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}
```

## Remove duplicates from unsorted LL

approach

1. nested loop
2. using map
3. sort and remove duplicates above logic

## Sort 0s 1s and 2s in LL

approach

1. count 0 1 and 2 and override data as per their count  
// if data replacement is not allowed then this method will get rejected

2. will create three pointer and each pointer will move head pointer one by one and will add those node to corresponding pointers.

```cpp
Node* sort2(Node* &head){
    if(head == NULL || head->next == NULL) return head;
    //create dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //traverse the original LL
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data == 0){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        } else if(curr->data == 1){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next = temp;
            oneTail = oneTail->next;
        } else { //data == 2
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next = temp;
            twoTail = twoTail->next;
        }
    }

    //join three LL

    //modify one LL
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;   
    //modify two LL
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp; 

    if(oneHead!=NULL){
        zeroTail->next = oneHead;
        if(twoHead!=NULL){
            oneTail->next = twoHead;
        }
    } else {
        if(twoHead!=NULL){
            zeroTail->next = twoHead;
        }
    }

    //remove zero head dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}
```

## Add two numbers represented by LL

approach

1. reverse both LL
2. add nodes
3. reverse ans again

```cpp
Node* reverseLL(Node * &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node* addLL(Node* &head1,Node* &head2){

    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    //reverse both LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    //adding 
    Node * ansHead = NULL;
    Node * ansTail = NULL;

    int carry = 0;
    while(head1!=NULL && head2!=NULL){
        int x = head1->data+head2->data+carry;
        carry = x /10;
        x = x%10;

        Node* newNode = new Node(x);
        if(ansHead == NULL){
            ansHead = newNode;
            ansTail = newNode;
        } else {
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1!=NULL){
        int x = head1->data + carry;
        carry = x / 10;
        x = x%10;
        Node* newNode = new Node(x);
        ansTail->next = newNode;
        ansTail = ansTail->next;
        head1 = head1->next;
    }
    while(head2!=NULL){
        int x = head2->data + carry;
        carry = x / 10;
        x = x%10;
        Node* newNode = new Node(x);
        ansTail->next = newNode;
        ansTail = ansTail->next;
        head2 = head2->next;
    }

    while(carry!=0){
        int x  = carry % 10;
        
        Node* newNode = new Node(x);
        ansTail->next = newNode;
        ansTail = ansTail->next;
        carry = carry / 10;
    }


    //reverse answer LL
    return reverseLL(ansHead);
}
//driver code
Node* ans = addLL(head1,head2);
```
