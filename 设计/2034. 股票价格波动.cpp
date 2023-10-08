/*
map维护各个时间戳对应的股票价格
set记录所有的股票及格，用来回答最值询问
latest记录的为map中最大的时间戳
*/
class StockPrice {
public:
    multiset<int> st;
    unordered_map<int,int> p;
    int latest=0;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if(p.count(timestamp)){
            st.erase(st.find(p[timestamp]));
        }
        p[timestamp]=price;
        st.insert(price);
        latest=max(latest,timestamp);
    }
    
    int current() {
        return p[latest];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};
