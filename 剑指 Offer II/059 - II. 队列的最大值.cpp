/*
一个普通队列q进行模拟，一个单调队列mx维护最大值
*/
class MaxQueue {
public:
    queue<pair<int,int>> q;
    deque<pair<int,int>> mx;
    int idx=0;
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
        return mx.front().first;
    }
    
    void push_back(int value) {
        ++idx;
        q.push({value,idx});
        while(!mx.empty()&&mx.back().first<value){
            mx.pop_back();
        }
        mx.push_back({value,idx});
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        if(mx.front().second==q.front().second) mx.pop_front();
        int x=q.front().first;
        q.pop();
        return x;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
