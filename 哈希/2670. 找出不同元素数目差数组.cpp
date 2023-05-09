/*
哈希表进行前后缀计数即可
*/
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> p,s;
        int n=nums.size();
        vector<int> ans;
        for(auto c:nums){
            s[c]++;
        }
        for(auto c:nums){
            p[c]++;
            if(!--s[c]){
                s.erase(c);
            }
            ans.push_back((int)p.size()-s.size());
        }
        return ans;
    }
};
