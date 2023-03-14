/*
定义状态：
dp[i][0]:表示以第i个数结尾，最小的子数组和
dp[i][1]:表示以第i个数结尾，最大的子数组和
转移方程：
因为nums[i]存在负数，对于负数，它的最大值则可能又前一个状态的最小值转换而来，所以需要同时维护最大值和最小值
dp[i][0]=min({dp[i-1][1]*nums[i],dp[i-1][0]*nums[i],nums[i]});
dp[i][1]=max({dp[i-1][1]*nums[i],dp[i-1][0]*nums[i],nums[i]});
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=dp[0][1]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=min({dp[i-1][1]*nums[i],dp[i-1][0]*nums[i],nums[i]});
            dp[i][1]=max({dp[i-1][1]*nums[i],dp[i-1][0]*nums[i],nums[i]});
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};
