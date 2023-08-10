/*
模拟题
*/
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        while(head){
            if(st.count(head->val)){
                ans+=!head->next||!st.count(head->next->val);
            }
            head=head->next;
        }
        return ans;
    }
};
