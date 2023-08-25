/*
遇到0就-1，遇到1就+1
状态定义：
dp[i][j]：表示一组集合，走到第i行第j列，能够获得的-1的个数种类和1的个数种类
这里可以用位运算优化，加一个偏移量，视105为0，遇到1则左移，遇到0则右移，最终看终点的集合中第105位是否为1即可
*/
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bitset<210>>> dp(n+1,vector<bitset<210>>(m+1));
        dp[0][1][105]=dp[1][0][105]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]){
                    dp[i][j]=(dp[i-1][j]<<1)|(dp[i][j-1]<<1);
                }else{
                    dp[i][j]=(dp[i-1][j]>>1)|(dp[i][j-1]>>1);
                }
            }
        }
        return dp[n][m][105];
    }
};
