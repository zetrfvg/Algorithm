/*
先只考虑一侧的房子放置的方案数
状态定义：
dp[i]：前i个地块放置房子的方案数
转移方程：
dp[i]=dp[i-1]+dp[i-2]

因为两侧放置房子相互独立，故答案为dp[n]*dp[n]
*/
class Solution {
public:
    int countHousePlacements(int n) {
        int dp[10010];
        memset(dp,0,sizeof dp);
        dp[1]=2,dp[2]=3;
        const int mod=1e9+7;
        for(int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
        return (1LL*dp[n]*dp[n])%mod;
    }
};
