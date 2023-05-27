/*
双指针枚举区间左端点，用set来维护区间元素
如果区间的最大值与最小值的差超过limit，则移动左指针
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int ans=0;
        int n=nums.size();
        for(int l=0,r=0;r<n;r++){
            st.insert(nums[r]);
            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[l++]));
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
