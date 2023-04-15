/*
状态定义：
dp[i][j]：以(i,j)为右下角顶点的正方形的最长边长
转移方程：
dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]){
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};
