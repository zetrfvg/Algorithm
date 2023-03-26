/*
哈希表
*/
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int s=nums[i]+nums[i-1];
            if(st.count(s)) return true;
            st.insert(s);
        }
        return false;
    }
};
