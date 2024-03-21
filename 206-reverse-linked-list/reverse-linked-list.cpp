class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = cur -> next;
            cur -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
        }
        return pre -> next;
    }
};