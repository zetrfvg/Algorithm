/*
每遇到一个)则将对应的序列翻转即可
*/
class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<char> st;
        for(auto c:s){
            if(c==')'){
                queue<char> q;
                while(1){
                    auto ch=st.top();
                    st.pop();
                    if(ch=='(') break;
                    q.push(ch);
                }
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }else{
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
