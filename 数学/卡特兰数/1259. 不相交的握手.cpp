class Solution {
public:
    int numberOfWays(int numPeople) {
        const int mod=1e9+7;
        vector<int> dp(numPeople+1,1);
        for(int i=2;i<=numPeople;i+=2){
            dp[i]=0;
            for(int j=1;j<i;j+=2){
                dp[i]=(1LL*dp[i]+1LL*dp[j-1]*dp[i-j-1])%mod;
            }
        }
        return dp.back();
    }
};
