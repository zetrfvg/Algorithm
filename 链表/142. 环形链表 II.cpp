/*
哈希表做法
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> p;
        while(head){
            if(p.count(head)) return head;
            p.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
