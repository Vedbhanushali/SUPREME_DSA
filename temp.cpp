
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