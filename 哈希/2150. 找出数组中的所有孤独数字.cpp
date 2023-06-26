/*
哈希表模拟
*/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> g;
        for(auto c:nums) g[c]++;
        vector<int> ans; 
        for(auto c:nums){
            if(g[c]==1&&!g.count(c-1)&&!g.count(c+1)){
                ans.push_back(c);
            }
        }
        return ans;
    }
};
