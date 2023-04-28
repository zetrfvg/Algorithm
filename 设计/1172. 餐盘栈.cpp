/*
维护一组栈，对于未满的栈，用一个小根堆来维护
push操作：
如果堆不为空，说明之前存在未满的栈，在下标最小的未满的栈中插入即可
如果堆为空，则说明之前的栈全部满了，则创建的一个新的栈把元素插入
popAtStack操作：
如果不存在当前下标的栈或者该栈为空，返回-1
如果该栈是满的，因为弹栈之后会变为不满，所以把该下标放入堆中，然后弹栈返回元素
pop操作：
执行调用最后一个栈逻辑的popAtStack操作

对于弹栈之后尾部可能会存在连续的空栈，这里使用了懒删除的技巧
*/
class DinnerPlates {
public:
    int capacity;
    vector<stack<int>> sts;
    priority_queue<int,vector<int>,greater<int>> q;;
    DinnerPlates(int capacity) {
        this->capacity=capacity;
    }
    
    void push(int val) {
        while(!q.empty()&&q.top()>=sts.size()) q.pop();
        if(q.empty()){
            stack<int> st;
            st.push(val);
            sts.emplace_back(st);
            if(capacity>1){
                q.push(sts.size()-1);
            }
        }else{
            auto &st=sts[q.top()];
            st.push(val);
            if(st.size()==capacity) q.pop();
        }
    }
    
    int pop() {
        return popAtStack(sts.size()-1);
    }
    
    int popAtStack(int index) {
        if(index>=sts.size()||sts[index].empty()){
            return -1;
        }
        auto &st=sts[index];
        if(st.size()==capacity){
            q.push(index);
        }
        int res=st.top();
        st.pop();
        while(sts.size()&&sts.back().empty()){
            sts.pop_back();
        }
        return res;
    }
};
