/*
维护一个单调递减的栈，每次模拟更新即可
*/
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {

    }
    
    int next(int price) {
        int res=1;
        while(!st.empty()&&st.top().first<=price){
            res+=st.top().second;
            st.pop();
        }
        st.push({price,res});
        return res;
    }
};
