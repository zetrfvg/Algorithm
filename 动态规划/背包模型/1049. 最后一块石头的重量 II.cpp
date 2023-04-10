/*
石头总重为sum
尽可能找到一种石头重量的组合之和来接近sum/2，这样它和另一部分相抵消后剩下的重量是最小
由此转化为从选出石头组合，形成不超过sum/2的最大价值的背包问题
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int k=sum/2,n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=stones[i-1]) dp[i][j]|=dp[i-1][j-stones[i-1]];
                if(dp[i][j]) ans=max(ans,j);
            }
        }
        return sum-ans*2;
    }
};
