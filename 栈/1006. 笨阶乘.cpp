/*
栈模拟计算过程
*/
class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        int op=0;
        while(--n){
            if(op==0) st.top()*=n;
            else if(op==1) st.top()/=n;
            else if(op==2) st.push(n);
            else st.push(-n);
            op=(op+1)%4;
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
