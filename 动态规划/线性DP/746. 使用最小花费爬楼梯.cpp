/*
状态定义：dp[i]为走到第i层花费的最少代价
转移方程：dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++) dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        return dp[n];
    }
};
