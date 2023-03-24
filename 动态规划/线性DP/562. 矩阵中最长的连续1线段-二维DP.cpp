/*
状态定义：
dp[i][j][0]：以第i行第j列的元素为终点的斜对角线的长度
dp[i][j][1]：以第i行第j列的元素为终点的竖直线的长度
dp[i][j][2]：以第i行第j列的元素为终点的水平线的长度
dp[i][j][3]：以第i行第j列的元素为终点的反斜对角线的长度
转移方程：
if(mat[i-1][j-1]==0){
    dp[i][j]={0,0,0,0};
}else{
    dp[i][j][0]=dp[i-1][j-1][0]+1;
    dp[i][j][1]=dp[i-1][j][1]+1;
    dp[i][j][2]=dp[i][j-1][2]+1;
    dp[i][j][3]=dp[i-1][j+1][3]+1;
}
*/
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+2,vector<int>(4)));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!mat[i-1][j-1]){
                    dp[i][j]={0,0,0,0};
                }else{
                    dp[i][j][0]=dp[i-1][j-1][0]+1;
                    dp[i][j][1]=dp[i-1][j][1]+1;
                    dp[i][j][2]=dp[i][j-1][2]+1;
                    dp[i][j][3]=dp[i-1][j+1][3]+1;
                    ans=max({ans,dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});
                }
            }
        }
        return ans;
    }
};
