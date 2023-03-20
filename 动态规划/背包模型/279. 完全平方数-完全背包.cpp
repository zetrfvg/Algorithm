/*
与322.零钱兑换一样
把这里的完全平方数当作零钱即可
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n);
        dp[0]=0;
        for(int i=1;i*i<=n;i++){
            int c=i*i;
            for(int j=c;j<=n;j++){
                dp[j]=min(dp[j],dp[j-c]+1);
            }
        }
        return dp[n];
    }
};
