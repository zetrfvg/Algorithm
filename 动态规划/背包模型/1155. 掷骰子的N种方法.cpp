/*
定义状态：
dp[i][j]：
前i个骰子和为j的方案数
转移方程：
dp[i][j]=Σdp[i-1][j-u]，其中j∈[1,k]
*/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                for(int u=1;u<=k;u++){
                    if(j>=u){
                        dp[i][j]=(1LL*dp[i][j]+dp[i-1][j-u])%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
