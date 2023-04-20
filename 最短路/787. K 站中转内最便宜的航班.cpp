/*
Bell-ford
经不超过k个点中转，即使用不超过k+1条边
跑k+1次Bell-ford算法即可
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int>(n,1e9));
        dp[0][src]=0;
        for(int i=1;i<=k+1;i++){
            for(auto &p:flights){
                int x=p[0],y=p[1],w=p[2];
                dp[i][y]=min(dp[i][y],dp[i-1][x]+w);
            }
        }
        int ans=1e9;
        for(int i=1;i<=k+1;i++){
            ans=min(ans,dp[i][dst]);
        }
        return ans==1e9?-1:ans;
    }
};
