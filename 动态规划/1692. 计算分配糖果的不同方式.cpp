/*
状态定义：
dp[i][j]：把i个糖果分给j个袋子的方案数
转移方程：
dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]
dp[i][j]比dp[i-1][j]多了一颗糖果，这颗糖果可以放在j个袋子中的任意一个
dp[i][j]比dp[i-1][j-1]多了一颗糖果和一个袋子，因为多了一个空袋子，因此糖果只能放在这个空袋子中
*/
class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(k+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=(1LL*dp[i-1][j]*j+dp[i-1][j-1])%mod;
            }
        }
        return dp[n][k];
    }
};
