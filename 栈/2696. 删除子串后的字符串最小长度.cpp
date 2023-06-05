/*
栈模拟即可
*/
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='B'&&!st.empty()&&st.top()=='A') st.pop();
            else if(c=='D'&&!st.empty()&&st.top()=='C') st.pop();
            else st.push(c);
        }
        return st.size();
    }
};
