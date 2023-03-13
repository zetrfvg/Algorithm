/*
状态定义：
dp[i][0]表示不偷第i间屋子能获得的最大价值；
dp[i][1]表示偷第i间屋子能获得的最大价值。
转移方程：
dp[i][0]=max(dp[i-1][0],dp[i-1][1])
dp[i][1]=dp[i-1][0]+nums[i]
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0,dp[0][1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
