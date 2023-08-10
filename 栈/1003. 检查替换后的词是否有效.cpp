/*
用栈来存储枚举过的字符，枚举到c时，如果前两个字符不为ab，则不合法，枚举到b时，如果前一个字符不为a，也不合法
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='c'){
                if(st.size()<2||st.top()!='b') return false;
                st.pop();
                if(st.top()!='a') return false;
                st.pop();
            }else if(c=='b'){
                if(!st.size()||st.top()!='a') return false;
                st.push(c);
            }else{
                st.push(c);
            }
        }
        return !st.size();
    }
};
