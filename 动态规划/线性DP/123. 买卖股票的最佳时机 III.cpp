/*
状态定义：
dp[i][j][k]：在第i天，完成了k笔交易获得的最大利润，j表示当天是否持有股票
转移方程：
dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n][2][3];
        memset(dp,-0x3f,sizeof dp);
        dp[0][1][0]=-prices[0];
        dp[0][0][0]=0;
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i][0][0]=0;
            dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
            dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
            dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
            dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
        }
        return max({dp[n-1][0][0],dp[n-1][0][1],dp[n-1][0][2]});
    }
};
