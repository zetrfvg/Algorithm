/*
将链表元素转化为一个数组
双指针模拟
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> s;
        ListNode* p=head;
        while(p){
            s.push_back(p->val);
            p=p->next;
        }
        int ans=0;
        for(int l=0,r=s.size()-1;l<r;l++,r--){
            ans=max(ans,s[l]+s[r]);
        }
        return ans;
    }
};
