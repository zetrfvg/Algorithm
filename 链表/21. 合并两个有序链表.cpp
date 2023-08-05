/*
双指针模拟合并
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans=NULL,*p=NULL;
        while(list1&&list2){
            if(list1->val<list2->val){
                if(!ans){
                    ans=p=new ListNode(list1->val);
                }else{
                    p->next=new ListNode(list1->val);
                    p=p->next;
                }
                list1=list1->next;
            }else{
                if(!ans){
                    ans=p=new ListNode(list2->val);
                }else{
                    p->next=new ListNode(list2->val);
                    p=p->next;
                }
                list2=list2->next;
            }
        }
        while(list1){
            if(!ans){
                ans=p=new ListNode(list1->val);
            }else{
                p->next=new ListNode(list1->val);
                p=p->next;
            }
            list1=list1->next;
        }
        while(list2){
            if(!ans){
                ans=p=new ListNode(list2->val);
            }else{
                p->next=new ListNode(list2->val);
                p=p->next;
            }
            list2=list2->next;
        }
        return ans;
    }
};
