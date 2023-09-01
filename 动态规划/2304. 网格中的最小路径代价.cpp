/*
状态定义：
dp[i][j]：到达第i行第j列格子的最小代价
转移方程：
dp[i][j]=min(dp[i-1][k]+moveCost[grid[i-1][k]][j])+grid[i][j]
*/
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        int ans=1e9;
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        for(int i=0;i<m;i++) dp[0][i]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]+=grid[i][j];
                if(i==n-1) ans=min(ans,dp[i][j]);
                else{
                    for(int k=0;k<m;k++){
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+moveCost[grid[i][j]][k]);
                    }
                }
            }
        } 
        return ans;
    }
};
