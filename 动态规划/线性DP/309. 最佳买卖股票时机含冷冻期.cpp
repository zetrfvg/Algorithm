/*
定义状态：
dp[i][0]：第i天没有股票也没有卖出股票获得的最大价值
dp[i][1]：第i天没有股票但是卖出了股票获得的最大价值
dp[i][2]：第i天持有股票的最大价值
转移方程：
dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
dp[i][1]=dp[i-1][2]+prices[i];
dp[i][2]=max(dp[i-1][2],dp[i-1][0]-prices[i]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][2]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][2]+prices[i];
            dp[i][2]=max(dp[i-1][2],dp[i-1][0]-prices[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
