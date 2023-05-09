/*
哈希表模拟即可
*/
class FrequencyTracker {
public:
    int c[100010];
    unordered_map<int,int> g;
    FrequencyTracker() {
        memset(c,0,sizeof c);
    }
    
    void add(int a) {
        if(g[a]) c[g[a]]--;
        g[a]++;
        c[g[a]]++;
    }
    
    void deleteOne(int a) {
        if(!g[a]) return;
        c[g[a]]--;
        g[a]--;
        if(g[a]) c[g[a]]++;
    }
    
    bool hasFrequency(int f) {
        return c[f];
    }
};
