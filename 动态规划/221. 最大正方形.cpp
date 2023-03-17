/*
状态定义：
dp[i][j]：以第i行第j列为右下角的正方形的最大边长
转移方程：
1、如果matrix[i][j]==1
dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
2、如果matrix[i][j]==0
dp[i][j]=0
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else if(matrix[i][j]-'0'){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
