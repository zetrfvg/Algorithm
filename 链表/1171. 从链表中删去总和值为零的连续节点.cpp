/*
两次遍历
第一次遍历哈希表记录每个前缀和出现的最后一个位置
第二次遍历用当前节点指向哈希表中同前缀和的后一个节点即可
*/
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root=new ListNode(0);
        root->next=head;
        int sum=0;
        unordered_map<int,ListNode*> g;
        for(auto p=root;p;p=p->next){
            sum+=p->val;
            g[sum]=p;
        }
        sum=0;
        for(auto p=root;p;p=p->next){
            sum+=p->val;
            p->next=g[sum]->next;
        }
        return root->next;
    }
};
