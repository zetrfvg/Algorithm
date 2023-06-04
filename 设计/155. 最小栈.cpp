/*
每个元素入栈的同时，记录一个当前元素到栈底的最小元素即可
*/
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else st.push({val,min(val,st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
