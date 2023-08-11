/*
栈模拟计算过程
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('&&s[i+1]==')'){
                st.push(1);
                i++;
            }else if(s[i]=='('){
                st.push(-1);
            }else{
                while(1){
                    int t=st.top();
                    st.pop();
                    if(st.top()==-1){
                        st.top()=t*2;
                        break;
                    }else{
                        st.top()+=t;
                    }
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
