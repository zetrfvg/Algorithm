/*
状态定义：
dp[i][j]：考虑前i个房子，第i个房子刷第j种颜色的最少费用
转移方程：
dp[i][0]=min(dp[i-1][1],dp[i-1][2])+costs[i-1][0];
dp[i][1]=min(dp[i-1][0],dp[i-1][2])+costs[i-1][1];
dp[i][2]=min(dp[i-1][0],dp[i-1][1])+costs[i-1][2];
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>> dp(n+1,vector<int>(3));
        for(int i=1;i<=n;i++){
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+costs[i-1][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+costs[i-1][1];
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+costs[i-1][2];
        }
        return min({dp[n][0],dp[n][1],dp[n][2]});
    }
};
