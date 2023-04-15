/*
栈模拟
遇到'('就直接入栈

遇到')'，如果栈空，说明不存在能够和他匹配的'('，就把他也入栈
否则，弹出一个栈顶元素与'('与它进行匹配，更新答案
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};
