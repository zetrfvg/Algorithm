/*
快慢指针解法
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto l=head,r=head;
        while(r&&r->next){
            l=l->next;
            r=r->next;
            r=r->next;
            if(l==r) return true;
        }
        return false;
    }
};
