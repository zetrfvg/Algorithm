/*
栈模拟即可，细节较多
*/
class Solution {
public:
    bool parseBoolExpr(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=n-1;~i;i--){
            if(s[i]==')') st.push(s[i]);
            else if(s[i]=='f') st.push('0');
            else if(s[i]=='t') st.push('1');
            else if(s[i]=='!'){
                int op=st.top()=='1';
                st.pop();
                st.pop();
                st.push('1'-op);
            }
            else if(s[i]=='&'){
                int op=1;
                while(st.top()!=')'){
                    op&=(st.top()=='1');
                    st.pop();
                }
                st.pop();
                st.push('0'+op);
            }else if(s[i]=='|'){
                int op=0;
                while(st.top()!=')'){
                    op|=(st.top()=='1');
                    st.pop();
                }
                st.pop();
                st.push('0'+op);
            }
        }
        return st.top()=='1';
    }
};
