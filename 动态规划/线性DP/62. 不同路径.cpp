/*
状态定义：
dp[i][j]：走到第i行第j列格子的方案数
状态转移：
dp[i][j]=dp[i-1][j]+dp[i][j-1];
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=0;i<m;i++) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

/*
公式法，从左上角到右下角的路径中一共要走m+n-2步
其中由m-1步是选择向右走
由组合数公式计算：
( m+n-2 )
(  m-1  ) 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans=1;
        for(int i=n,j=1;j<m;i++,j++){
            ans=ans*i/j;
        }
        return ans;
    }
};
