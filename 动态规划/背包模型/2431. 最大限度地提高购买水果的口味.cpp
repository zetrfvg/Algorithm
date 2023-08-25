/*
状态定义：
dp[i][j][k]：前i个物品花费j元，使用k次打折后能够获得的最大口味
转移方程：见注释
*/
class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n=tastiness.size();
        int dp[n+1][maxAmount+1][maxCoupons+1];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=maxAmount;j++){
                for(int k=0;k<=maxCoupons;k++){
                    dp[i][j][k]=dp[i-1][j][k];//不买第i个物品
                    if(j>=price[i-1]) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-price[i-1]][k]+tastiness[i-1]);//不使用打折
                    if(k&&j>=price[i-1]/2) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-price[i-1]/2][k-1]+tastiness[i-1]);//使用打折
                }
            }
        }
        int ans=0;
        for(int i=0;i<=maxCoupons;i++) ans=max(ans,dp[n][maxAmount][i]);
        return ans;
    }
};
