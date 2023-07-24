/*
哈希表模拟
*/
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> g;
        for(auto c:nums) g[c]++;
        for(int i=0;i<moveTo.size();i++){
            int c=g[moveFrom[i]];
            g[moveFrom[i]]=0;
            g[moveTo[i]]+=c;
        }
        vector<int> ans;
        for(auto &[a,b]:g) if(b) ans.push_back(a);
        return ans;
    }
};
