/*
双指针枚举右端点，当区间中0的数量超过1时移动左端点
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0,cur=0;
        for(int l=0,r=0;r<n;r++){
            cur+=nums[r]==0;
            while(cur>1) cur-=nums[l++]==0;
            ans=max(ans,r-l);
        }
        return ans;
    }
};
