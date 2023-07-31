/*
将结点存到数组上，用双指针进行合并即可
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<ListNode*> p;
        while(head){
            p.push_back(head);
            head=head->next;
        }
        int l=0,r=p.size()-1;
        while(l<r){
            if(!head) head=p[l];
            p[l]->next=p[r];
            l++;
            if(l==r) break;
            p[r]->next=p[l];
            r--;
        }
        p[l]->next=NULL;
    }
};
