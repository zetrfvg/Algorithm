/*
状态定义：
dp[i]：i是一个二进制数，来表示自行车被选用的状态，如00110表示第1和第2台自行车被选用了，dp[i]表示在这种状态下，最小的曼哈顿距离
转移方程：
dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+abs(workers[cnt][0]-bikes[j][0])+abs(workers[cnt][1]-bikes[j][1]))
*/
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n=workers.size(),m=bikes.size();
        vector<int> dp(1<<m,1e9);
        dp[0]=0;
        int ans=1e9;
        for(int i=0;i<(1<<m);i++){
            int cnt=__builtin_popcount(i);
            if(cnt==n){
                ans=min(ans,dp[i]);
            }
            if(cnt>=n) continue;
            for(int j=0;j<m;j++){
                if(!((i>>j)&1)){
                    dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+abs(workers[cnt][0]-bikes[j][0])+abs(workers[cnt][1]-bikes[j][1]));
                }
            }
        }
        return ans;
    }
};
