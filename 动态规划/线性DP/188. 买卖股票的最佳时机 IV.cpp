/*
状态定义：
dp[i][j][k]：在第i天，完成了k笔交易获得的最大利润，j表示当天是否持有股票
转移方程：
dp[i][0][k]=max(dp[i-1][0][k],dp[i-1][1][k-1]+prices[i]);
dp[i][1][k]=max(dp[i-1][1][k],dp[i-1][0][k]-prices[i]);
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[n][2][k+1];
        memset(dp,-0x3f,sizeof dp);
        dp[0][1][0]=-prices[0],dp[0][0][0]=0;
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i][0][0]=0;
            dp[i][1][0]=max(dp[i-1][1][0],-prices[i]);
            for(int j=1;j<=k;j++){
                dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][1][j-1]+prices[i]);
                dp[i][1][j]=max(dp[i-1][1][j],dp[i-1][0][j]-prices[i]);
                if(i==n-1) ans=max(ans,dp[i][0][j]);
            }
        }
        return ans;
    }
};
