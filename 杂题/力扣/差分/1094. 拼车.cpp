class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> g(1010);
        for(auto p:trips){
            g[p[1]+1]+=p[0];
            g[p[2]+1]-=p[0];
        }
        for(int i=1;i<=1001;i++){
            g[i]+=g[i-1];
            if(g[i]>capacity) return false;
        }
        return true;
    }
};
