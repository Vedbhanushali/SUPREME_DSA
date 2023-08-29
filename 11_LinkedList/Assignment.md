# Assignment of Linked List

## Print kth node from end of Linked List

4 5 3 2 1  , k =1, 0-indexed linked list  

answer is 2

approach

- reverse the LL and return the pos index node data
- find the lenght of LL and return (n-pos) index from start
- recursive solution when reached end of LL and returning we will start count when moving out of function.

```cpp
void solve(Node* &head,int &pos,int &ans){
    if(head==NULL) return;

    solve(head->next,pos,ans);

    if(pos==0) ans = head->data;
    pos--;
}
int getNode(Node* head,int pos){
    int ans = -1;
    solve(head,pos,ans);
    return ans;
}
```

## Intersection point of 2 Linked list

<https://leetcode.com/problems/intersection-of-two-linked-lists/>

approach

- will move both pointers of LL to end node if any one is reached, now the other one which is not reached end will move that count the nodes between till end.
- count will give how much more distance of LL1 is more than LL2, so will skip those node from bigger LL and will start comparing till nodes address become same which is intersecting point

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        while(l1->next!=NULL && l2->next!=NULL){
            if(l1 == l2){
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1->next==NULL){
            //L2 is bigger
            int gap = 0;
            while(l2->next!=NULL){
                gap++;
                l2 = l2->next;
            }
            while(gap--){
                headB = headB->next;
            }
        } else {
            //L1 is bigger
            int gap = 0;
            while(l1->next!=NULL){
                gap++;
                l1 = l1->next;
            }
            while(gap--){
                headA = headA->next;
            }
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
// another method
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=NULL){
            temp1 = temp1->next;
            l1++;
        }
        while(temp2!=NULL){
            temp2 = temp2->next;
            l2++;
        }
        
        int jump = 0;
        if(l1>l2){
            temp1 = headA;
            temp2 = headB;
            jump = l1-l2; //list1 is bigger
            while(jump--){
                temp1 = temp1->next;
            }
        } 
        else{
            temp1 = headA;
            temp2 = headB;
            jump = l2-l1; //list1 is bigger
            while(jump--){
                temp2 = temp2->next;
            }
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            } else {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return NULL;
        
    }
```

## Merge 2 Sorted Linked List

<https://leetcode.com/problems/merge-two-sorted-lists/>

approach

```cpp

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode();
        ListNode* currentNode = ans;

        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                currentNode->next = left;
                left = left->next;
            } else {
                currentNode->next = right;
                right = right->next;
            }
            currentNode = currentNode->next;
        }
        if(left==NULL){
            currentNode->next = right;
        } 
        if(right==NULL){
            currentNode->next = left;
        }
        return ans->next;
    }
};
```

## Merge Sort in Linked list

<https://leetcode.com/problems/sort-list/>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode();
        ListNode* currentNode = ans;

        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                currentNode->next = left;
                left = left->next;
            } else {
                currentNode->next = right;
                right = right->next;
            }
            currentNode = currentNode->next;
        }
        if(left==NULL){
            currentNode->next = right;
        } 
        if(right==NULL){
            currentNode->next = left;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        //sort RE
        left = sortList(left);
        right = sortList(right);

        //merge
        return mergeTwoLists(left,right);
    }
};
```

## Flatten a Linked List

<https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1>

approach  
mergeing LL recursively and also traversing LL recursively

Question  
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

Example 1:

```
Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
```

```cpp
/* Node structure  used in the program
struct Node{
 int data;
 struct Node * next;
 struct Node * bottom;
 
 Node(int x){
     data = x;
     next = NULL;
     bottom = NULL;
 }
 
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node* merge(Node* a, Node* b) {
        if(a == NULL) return b;
        if(b == NULL) return a; 
        
        Node* ans = 0;
        if(a->data < b->data){
            ans = a;
            a->bottom = merge(a->bottom,b);
        } else {
            ans = b;
            b->bottom = merge(a,b->bottom);
        }
        return ans;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(!root) return 0;
   Node* mergedLL = merge(root,flatten(root->next));
   return mergedLL;
}
```

## Clone a Linked List with Random Pointer

<https://leetcode.com/problems/copy-list-with-random-pointer/description/>

```cpp
//recursive
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* helper_old(Node* head,unordered_map<Node*,Node*> &hashMap){
        if(head == 0) return 0;
        Node* newHead = new Node(head->val);
        hashMap[head] = newHead;
        newHead->next = helper_old(head->next,hashMap);
        if(head->random){
            newHead->random = hashMap[head->random];
        }
        return newHead;
    }
    Node* helper(Node* head){
        if(head == 0 ) return head;
        //inserting new items after one another
        Node* it = head;
        while(it!=NULL){
            Node* newNode = new Node(it->val);
            newNode->next = it->next;
            it->next = newNode;
            it = it->next->next;
        }
        it = head;
        while(it){
            Node* temp = it->next;
            temp->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }
        //detaching new node
        it = head;
        Node* newListHead = it->next;
        while(it){
            Node* temp = it->next;
            if(it->next)
                it->next = it->next->next;
            it = temp;
        }
        return newListHead;
    }
    Node* copyRandomList(Node* head) {
        // unordered_map<Node* ,Node*> hashMap;
        // return helper_old(head,hashMap);
        return helper(head);

    }
};
```

## rotate List (Leetcode)

```cpp

```

## Delete n nodes after m nodes (Leetcode)

## Find min/max number between critical points (Leetcode)

## Merge Node in between zeroes (Leetcode)
