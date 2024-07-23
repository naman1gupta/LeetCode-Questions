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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL and fast->next!=NULL ){
        //     if(fast==NULL){
        //         int poss=pos;
        //         fast=head;
        //         while(poss--){
        //             fast=fast->next;
        //         }
        //     }
        //     if(fast->next==NULL){
        //         fast->next=head;
        //         int poss=pos;
        //         fast=head;
        //         while(poss--){
        //             fast=fast->next;
        //         }
        //     }
            slow=slow->next;
            fast=fast->next->next;
            if(slow ==fast) return true;
            // if(slow->next==NULL) return false;
        }
        return false;
    }
};