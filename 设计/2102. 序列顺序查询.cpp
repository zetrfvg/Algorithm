/*
平衡树模拟即可
*/
class SORTracker {
public:
    set<pair<int,string>> st;
    set<pair<int,string>>::iterator cur;
    
    SORTracker() {
        st.insert({0,""});
        cur=st.begin();
    }
    
    void add(string name, int score) {
        pair<int,string> p={-score,name};
        st.insert(p);
        if(p<*cur) cur--;
    }
    
    string get() {
        return cur++->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
