/*
对于每个插入的元素x，赋予其一个编号idx，用一个数组来维护编号为idx是否被移除出了栈
取最大值的操作通过一个set来实现
*/
class MaxStack {
public:
    stack<pair<int,int>> st;
    vector<int> vis;
    int idx=0;
    set<pair<int,int>> heap;
    MaxStack() {
        vis.assign(70000,0);
    }
    
    void push(int x) {
        st.push({x,++idx});
        heap.insert({x,idx});
    }
    
    int pop() {
        while(vis[st.top().second]) st.pop();
        vis[st.top().second]=1;
        int res=st.top().first;
        st.pop();
        return res;
    }
    
    int top() {
        while(vis[st.top().second]) st.pop();
        return st.top().first;
    }
    
    int peekMax() {
        while(vis[heap.rbegin()->second]) heap.erase(*heap.rbegin());
        return heap.rbegin()->first;
    }
    
    int popMax() {
        while(vis[heap.rbegin()->second]) heap.erase(*heap.rbegin());
        vis[heap.rbegin()->second]=1;
        int res=heap.rbegin()->first;
        heap.erase(*heap.rbegin());
        return res;
    }
};
