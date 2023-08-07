/*
枚举两两相邻的结点，模拟插入过程即可
*/
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *l=head,*r=head->next;
        while(r){
            l->next=new ListNode(__gcd(l->val,r->val));
            l->next->next=r;
            l=r,r=r->next;
        }
        return head;
    }
};
