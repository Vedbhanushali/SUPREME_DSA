# hashMap and Tries Assignment

## Array subset of another array

<https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1>

```cpp
string isSubset(int a1[], int a2[], int n, int m) {
    if(n < m) return "No";
    unordered_map<int,int> hashMap;
    for(int i=0;i<n;i++){
        hashMap[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        // cout<<a2[i]<<" "<<hashMap[a2[i]]<<endl;
        if(hashMap[a2[i]]==0){
            return "No";
        } else {
            hashMap[a2[i]]--;
        }
        // cout<<a2[i]<<" - "<<hashMap[a2[i]]<<endl;
    }
    return "Yes";
}
```

## Union of two linked list

<https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1>

```cpp
class Solution
{
    public:
    struct Node*makeUnion(struct Node* head1, struct Node*head2)
    {
        // code here
        map<int,Node*> hashMap;
        Node*temp = head1;
        while(temp){
            hashMap[temp->data] = temp;
            temp = temp->next;
        }
        temp = head2;
        while(temp){
            hashMap[temp->data] = temp;
            temp = temp->next;
        }
        temp = NULL;
        Node* ans = temp;
        for(auto i:hashMap){
            // cout<<i.second->data<<endl;
            if(temp == NULL){
                temp = i.second;
                ans = temp;
            } else {
                temp->next = i.second;
                temp = temp->next;
            }
            // cout<<temp->data<<" "<<endl;
        }
        temp->next = NULL;
        return ans;
    }
};
```

## Intersection of two linked list

<https://leetcode.com/problems/intersection-of-two-linked-lists/>

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
        // int l1 = 0;
        // int l2 = 0;
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // while(temp1!=NULL){
        //     temp1 = temp1->next;
        //     l1++;
        // }
        // while(temp2!=NULL){
        //     temp2 = temp2->next;
        //     l2++;
        // }
        
        // int jump = 0;
        // if(l1>l2){
        //     temp1 = headA;
        //     temp2 = headB;
        //     jump = l1-l2; //list1 is bigger
        //     while(jump--){
        //         temp1 = temp1->next;
        //     }
        // } 
        // else{
        //     temp1 = headA;
        //     temp2 = headB;
        //     jump = l2-l1; //list1 is bigger
        //     while(jump--){
        //         temp2 = temp2->next;
        //     }
        // }
        // while(temp1!=NULL && temp2!=NULL){
        //     if(temp1==temp2){
        //         return temp1;
        //     } else {
        //         temp1=temp1->next;
        //         temp2=temp2->next;
        //     }
        // }
        // return NULL;

    }
};
```

approach using hashMap

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
        unordered_map<ListNode*,int > hashMap;
        ListNode* temp = headA;
        while(temp){
            hashMap[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        ListNode* ans = NULL;
        while(temp){
            if(hashMap.count(temp)>0){
                ans = temp;
                break;
            }
            temp = temp->next;
        }
        return ans;
    }
};
```

## Sum equal to sum

<https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1>

```cpp
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        int ans = 0;
        unordered_map<long long,int> hashMap;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++) {
                int sum = a[i] + a[j];
                if(hashMap.count(sum) == 0){
                    // cout<<"unique"<<sum<<endl;
                    hashMap[sum]++;
                } else {
                    // cout<<"present"<<sum<<endl;
                    return 1;
                }    
            }
            
        }
        return 0;
    }
};
```

## largest subarray with 0 sum

<https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1>

```cpp
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        // Your code here
        unordered_map<int,int> hashMap;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(sum == 0){
                ans = max(ans,i+1);
            }
            else if(hashMap.count(sum) == 0){
                //does not exist
                hashMap[sum] = i;
            } else {
                //exist before
                // 2-0;
                ans = max(ans,i-hashMap[sum]);
            }
        }
        return ans;
    }
};
```
