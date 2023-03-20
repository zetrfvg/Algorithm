/*
状态定义：
dp[j]：组成价值总和为i的最少零钱个数
状态转移：
枚举所有硬币
dp[j]=min(dp[j-coins[i]]+1,dp[j])
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(auto c:coins){
            for(int j=c;j<=amount;j++){
                dp[j]=min(dp[j],dp[j-c]+1);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};
