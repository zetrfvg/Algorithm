/*
状态定义：
dp[i][j]：考虑第size1组前i个点，和size2的子集j连通的最低成本
*/
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size(),m=cost[0].size();
        vector<vector<int>> dp(n+1,vector<int>(1<<m,1e9));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<m);j++){
                for(int k=0;k<m;k++){
                    if(j&(1<<k)){
                        dp[i][j]=min(dp[i][j],dp[i][j^(1<<k)]+cost[i-1][k]);//size2中第k个点只与size1中的第i个点连通
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+cost[i-1][k]);//size1中的第i个点只和size2中的第k个点连通
                        dp[i][j]=min(dp[i][j],dp[i-1][j^(1<<k)]+cost[i-1][k]);//size1中的第i个点和size2中的第k个点，二者相互连通，且不与之外的任何点连通
                        //三种情况的代价取最小值
                    }
                }
            }
        }
        return dp[n][(1<<m)-1];
    }
};
