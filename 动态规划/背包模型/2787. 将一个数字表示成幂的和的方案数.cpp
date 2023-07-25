/*
背包问题求方案数
物品i的价值为pow(i,x)
用若干个物品凑成总价值为n的方案数
*/
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<long long> p(n+1);
        const int mod=1e9+7;
        for(int i=1;i<=n;i++){
            p[i]=1;
            for(int j=1;j<=x;j++) p[i]*=i;
        }
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=p[i];j--){
                dp[j]=(dp[j]+dp[j-p[i]])%mod;
            }
        }
        return dp[n];
    }
};
