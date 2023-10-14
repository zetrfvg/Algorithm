/*
模拟
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> p;
        for(auto c:nums) p[c]++;
        for(auto [a,b]:p) if(b&1) return a;
        return -1;
    }
};
