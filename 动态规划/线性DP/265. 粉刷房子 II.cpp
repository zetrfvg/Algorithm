/*
状态定义：
dp[i][j]：考虑前i个房子，第i个房子刷第j种颜色的最小花费
转移方程：
fi是前考虑前i-1个房子中，花费最小的颜色
se是前考虑前i-1个房子中，花费次小的颜色
if(j==fi) dp[i][j]=dp[i-1][se]+costs[i-1][j];
else dp[i][j]=dp[i-1][fi]+costs[i-1][j];
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size(),k=costs[0].size();
        vector<vector<int>> dp(n+1,vector<int>(k));
        for(int i=1;i<=n;i++){
            int fi=-1,se=-1;
            for(int j=0;j<k;j++){
                if(fi==-1||dp[i-1][fi]>dp[i-1][j]){
                    se=fi;
                    fi=j;
                }else if(se==-1||dp[i-1][se]>dp[i-1][j]){
                    se=j;
                }
            }
            for(int j=0;j<k;j++){
                if(j==fi){
                    dp[i][j]=dp[i-1][se]+costs[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][fi]+costs[i-1][j];
                }
            }
        }
        return *min_element(dp[n].begin(),dp[n].end());
    }
};
