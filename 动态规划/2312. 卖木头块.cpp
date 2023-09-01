/*
预处理出切割高h，宽w的木头的价值，直接存入DP数组
状态定义：
dp[i][j]：切割前i行，前j列的木头获得的最大价值
转移方程：
dp[i][j]=max(max(dp[i][j-k]),max(dp[i-k][j]))
*/
class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(n+1,vector<long long>(m+1));
        for(auto &pr:prices){
            dp[pr[0]][pr[1]]=pr[2];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<j;k++) dp[i][j]=max(dp[i][j],dp[i][k]+dp[i][j-k]);//水平切割
                for(int k=1;k<i;k++) dp[i][j]=max(dp[i][j],dp[k][j]+dp[i-k][j]);//竖直切割
            }
        }
        return dp[n][m];
    }
};
