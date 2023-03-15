/*
状态定义：
dp[i][j]：表示下降走到第i行第j列所获的最小值
转移方程：
dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]+=min({matrix[i-1][max(0,j-1)],matrix[i-1][j],matrix[i-1][min(m-1,j+1)]});
            }
        }
        return *min_element(matrix.back().begin(),matrix.back().end());
    }
};
