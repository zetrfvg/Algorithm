/*
状态定义：
dp[i][j][k]：考虑前i个任务，最多有j个人参与，能够获得价值至少为k的方案数
转移方程：
容易想到dp[i][j][k]=Σdp[i-1][j-groups[i-1]][k-profit[i-1]]
这里需要注意k-profit[i-1]可能为负，而这个负数也是满足定义的，它代表的是考虑前i个任务，最多有j个人参与，能够获得价值至少为k-profit[i-1]的方案数
此时，为了处理这种情况，可以把利润至少为负数的情况视作于利润至少为0的情况，这二者是等价的
于是完成了状态的转移
*/
class Solution {
public:
    int profitableSchemes(int m, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod=1e9+7;
        int n=group.size();
        int dp[n+1][m+1][minProfit+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<=m;i++) dp[0][i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=minProfit;k++){
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j>=group[i-1]){
                        dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-group[i-1]][max(0,k-profit[i-1])])%mod;
                    }
                }
            }
        }
        return dp[n][m][minProfit];
    }
};
