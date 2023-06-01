/*
滑动窗口枚举所有长度为k+1的区间，区间内的元素用哈希表计数即可
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n=nums.size();
        for(int l=0,r=0;r<n;r++){
            if(st.count(nums[r])) return true;
            st.insert(nums[r]);
            if(r>=k) st.erase(nums[l++]);
        }
        return false;
    }
};
