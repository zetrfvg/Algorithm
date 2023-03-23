/*
状态定义：
dp[i][0]：不操作第i个数，第i个数结尾的最大子数组和
dp[i][1]：操作第i个数，第i个数结尾的最大子数组和
转移方程：
dp[i][0]=max(nums[i-1],dp[i-1][0]+nums[i-1]);
dp[i][1]=max({dp[i-1][1]+nums[i-1],nums[i-1]*nums[i-1],dp[i-1][0]+nums[i-1]*nums[i-1]});
*/
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(2));
        for(int i=1;i<=n;i++){
            dp[i][0]=max(nums[i-1],dp[i-1][0]+nums[i-1]);
            dp[i][1]=max({dp[i-1][1]+nums[i-1],nums[i-1]*nums[i-1],dp[i-1][0]+nums[i-1]*nums[i-1]});
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};
