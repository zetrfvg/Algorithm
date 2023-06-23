/*
递归的方式找到这两个节点
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p,*q;
        function<int(ListNode*,int)> get=[&](ListNode* head,int a){
            if(!head) return 1;
            if(a==k) p=head;
            int b=get(head->next,++a);
            if(b==k) q=head;
            return b+1;
        };
        get(head,1);
        swap(p->val,q->val);
        return head;
    }
};
