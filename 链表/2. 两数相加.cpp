/*
链表模拟，高精度加法
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=NULL,*p;
        int res=0;
        for(ListNode *l=l1,*r=l2;l||r;){
            if(l){
                res+=l->val;
                l=l->next;
            }
            if(r){
                res+=r->val;
                r=r->next;
            }
            ListNode *t=new ListNode(res%10);
            if(!ans) ans=t;
            else p->next=t;
            p=t;
            res/=10;
        }
        if(res) p->next=new ListNode(res);
        return ans;
    }
};
