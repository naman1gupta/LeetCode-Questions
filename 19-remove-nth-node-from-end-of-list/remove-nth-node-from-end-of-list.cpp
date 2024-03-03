class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* okk = new ListNode(0);
        okk->next = head;
        ListNode* first = okk;
        ListNode* second = okk;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return okk->next;
    }
};