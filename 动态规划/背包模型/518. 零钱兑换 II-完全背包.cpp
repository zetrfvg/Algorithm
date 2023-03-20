/*
状态定义：
dp[j]：价值为j的零钱组合方案数
转移方程：
依次枚举零钱
dp[j]+=dp[j-c]
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0]=1;
        for(auto c:coins){
            for(int j=c;j<=amount;j++){
                dp[j]+=dp[j-c];
            }
        }
        return dp[amount];
    }
};
