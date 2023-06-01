/*
状态定义：
dp[i][j]：以nums1第i个数字和nums2第j个数字开始的最长重复子数组
转移方程：
if(nums1[i]==nums[j]) dp[i][j]=dp[i+1][j+1]+1
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        int ans=0;
        for(int i=n-1;~i;i--){
            for(int j=m-1;~j;j--){
                if(nums1[i]==nums2[j]) dp[i][j]=dp[i+1][j+1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
