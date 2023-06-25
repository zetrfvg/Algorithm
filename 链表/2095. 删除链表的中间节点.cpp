/*
快慢指针法
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        auto l=head,r=head;
        ListNode* pre=NULL;
        while(r&&r->next){
            pre=l;
            l=l->next;
            r=r->next->next;
        }
        pre->next=l->next;
        return head;
    }
};
