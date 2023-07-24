/*
状态定义：
dp[i][0]：考虑前i个元素，以nums1[i]结尾的最长子数组长度
dp[i][1]：考虑前i个元素，以nums2[i]结尾的最长子数组长度
转移方程：
if(nums1[i]>=nums1[i-1]) dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
if(nums1[i]>=nums2[i-1]) dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
if(nums2[i]>=nums1[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
if(nums2[i]>=nums2[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
*/
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int ans=1;
        vector<vector<int>> dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++){
            if(nums1[i]>=nums1[i-1]) dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
            if(nums1[i]>=nums2[i-1]) dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
            if(nums2[i]>=nums1[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
            if(nums2[i]>=nums2[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};
