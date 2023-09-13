/*
状态定义：
dp[i][0]：第i个房子刷的颜色和前一个不同的方案数
dp[i][1]：第i个房子刷的颜色和前一个相同的方案数
转移方程：
dp[i][0]=dp[i-1][0]*(k-1)+dp[i-1][1]*(k-1);
dp[i][1]=dp[i-1][0];
*/
class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=k,dp[0][1]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]*(k-1)+dp[i-1][1]*(k-1);
            dp[i][1]=dp[i-1][0];
        }
        return dp[n-1][0]+dp[n-1][1];
    }
};
