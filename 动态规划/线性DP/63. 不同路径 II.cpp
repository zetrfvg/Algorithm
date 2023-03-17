/*
状态定义：
dp[i][j]：走到第i行第j列格子的方案数
转移方程：
dp[i][j]=obstacleGrid[i][j]?0:dp[i-1][j]+dp[i][j-1]
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]) break;
            dp[i][0]=1;
        }
        for(int j=0;j<m;j++){
            if(obstacleGrid[0][j]) break;
            dp[0][j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
