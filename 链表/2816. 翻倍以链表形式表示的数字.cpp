/*
从低位开始乘2，同时向高位进位，模拟乘法过程，递归实现即可
*/
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        function<int(ListNode*)> dfs=[&](ListNode* cur){
            if(!cur) return 0;
            int res=(cur->val)*2+dfs(cur->next);
            cur->val=res%10;
            return res/10;
        };
        int rest=dfs(head);
        if(rest){
            ListNode *p=new ListNode(rest);
            p->next=head,head=p;
        }
        return head;
    }
};
