/*
哈希表模拟
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> g;
        for(auto c:nums) g[c]++;
        for(auto p:g) if(p.second==1) return p.first;
        return -1;
    }
};
