/*
模拟栈操作，最后判是否栈空即可
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        for(int i=0,j=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty()&&popped[j]==st.top()){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};
