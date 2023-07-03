/*
栈模拟，头插法创建链表
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        for(auto p=l1;p;p=p->next){
            s1.push(p->val);
        }
        for(auto p=l2;p;p=p->next){
            s2.push(p->val);
        }
        ListNode *ans=NULL,*p;
        int rest=0;
        while(!s1.empty()||!s2.empty()||rest){
            if(!s1.empty()){
                rest+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                rest+=s2.top();
                s2.pop();
            }
            p=new ListNode(rest%10);
            if(ans) p->next=ans;
            ans=p;
            rest/=10;
        }
        return ans;
    }
};
