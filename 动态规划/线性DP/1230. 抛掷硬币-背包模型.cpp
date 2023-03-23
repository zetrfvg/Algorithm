/*
状态定义：
dp[i][j]：考虑掷出前i个硬币，有j个硬币朝上的概率
转移方程：
dp[i][j]=Σdp[i-1][j]*(1-prob[i-1])+dp[i-1][j-1]*prob[i-1];
*/
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n=prob.size();
        vector<vector<double>> dp(n+1,vector<double>(target+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]*(1-prob[i-1]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                dp[i][j]=dp[i-1][j]*(1-prob[i-1])+dp[i-1][j-1]*prob[i-1];
            }
        }
        return dp[n][target];
    }
};
