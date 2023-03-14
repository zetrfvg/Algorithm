/*
定义状态：
dp[i][0]:在第i天没有股票的同时获得的最大价值
dp[i][1]:在第i天持有股票的同时获得的最大价值
状态转移：
dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }
        return dp[n-1][0];
    }
};
