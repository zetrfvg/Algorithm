class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> c(26);
        for(auto &ch:word) c[ch-'a']++;
        unordered_map<int,int> g;
        for(auto &cc:c) if(cc) g[cc]++;
        for(auto &cc:c){
            if(!cc) continue;
            if(!--g[cc]) g.erase(cc);
            if(cc>1) g[cc-1]++;
            if(g.size()==1){
                return true;
            }
            if(cc>1){
                if(!--g[cc-1]){
                    g.erase(cc-1);
                }
            }
            g[cc]++;
        }
        return false;
    }
};
