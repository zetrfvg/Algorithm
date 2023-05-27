/*
经典双指针枚举右端点
区间中0的个数超过k便移动左端点
取区间长的最大值
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,cur=0;
        for(int l=0,r=0;r<n;r++){
            cur+=nums[r]==0;
            while(cur>k) cur-=nums[l++]==0;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
