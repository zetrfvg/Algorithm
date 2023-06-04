/*
排序后哈希表模拟
*/
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<int> st;
        sort(nums.begin(),nums.end());
        for(int l=0,r=nums.size()-1;l<r;l++,r--){
            st.insert(nums[l]+nums[r]);
        }
        return st.size();
    }
};
