/*
递归模拟
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* res=head->next;
        head->next=swapPairs(res->next);
        res->next=head;
        return res;
    }
};
