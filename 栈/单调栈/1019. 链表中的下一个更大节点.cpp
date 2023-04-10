/**
从最后一个节点开始递归，维护一个单调递增的栈
枚举到第i个节点，把栈中小于等于节点i的元素全部弹出，剩下的栈顶元素就是节点i的下一个更大节点
把i入栈
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> ans;
        function<void(ListNode*)> fun=[&](ListNode* head){
            if(!head) return;
            fun(head->next);
            while(!st.empty()&&head->val>=st.top()) st.pop();
            if(!st.empty()){
                ans.push_back(st.top());
            }else{
                ans.push_back(0);
            }
            st.push(head->val);
        };
        fun(head);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
