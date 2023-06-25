/*
状态定义：
dp[i][j]：前i堵墙中，两位油漆工至少刷了j堵墙的最少开销
转移方程：
dp[i][j]=min(dp[i-1][j],dp[i-1][j-time[i-1]-1])
*/
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];//用付费的油漆工刷第i堵墙
                dp[i][j]=min(dp[i][j],dp[i-1][max(j-time[i-1]-1,0)]+cost[i-1]);//用免费的油漆工刷第i堵墙
            }
        }
        return dp[n][n];
    }
};
