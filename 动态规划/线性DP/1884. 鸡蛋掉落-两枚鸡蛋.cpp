/*
状态定义：
dp[i][0]：有1个鸡蛋时，验证i层楼需要的最少操作数
dp[i][1]：有2个鸡蛋时，验证i层楼需要的最少操作数
转移方程：
假设从[1,i]中选从第j层楼抛下一个鸡蛋，
如果碎了，那么验证i层楼的最少操作数为dp[j-1][0]+1
如果没碎，那么验证i层楼的最少操作数为dp[i-j][1]+1
则从第j层楼抛下一个鸡蛋来验证i层楼的最少操作数为：max(dp[j-1][0]+1,dp[i-j][1]+1)
枚举[1,i]中所有的j，取最小值即为验证i层楼的最少操作数
*/
class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,1e9));
        dp[0][0]=dp[0][1]=0;
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][1]=min(dp[i][1],max(dp[j-1][0]+1,dp[i-j][1]+1));
            }
        }
        return dp[n][1];
    }
};
