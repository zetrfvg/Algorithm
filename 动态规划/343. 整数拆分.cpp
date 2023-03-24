/*
状态定义：
dp[i]：将i拆分成至少两个数的最大乘积
转移方程：
将i拆分为j与i-j：
将i-j继续拆分：dp[i]=max(dp[i],j*dp[i-j])
将i-j不继续拆分：dp[i]=max(dp[i],j*(i-j))
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max({dp[i],j*dp[i-j],j*(i-j)});
            }
        }
        return dp[n];
    }
};
