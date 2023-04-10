/*
定义状态：
dp[i][j]：在第i个星期到达城市j时最大的休假天数
转移方程：
dp[i][x]=max(dp[i-1][y]+days[x][i-1])，其中y城市必须可达，并且存在y城市到x城市的航班或者x和y指同一个城市
*/
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n=flights.size();
        int k=days.size();
        int dp[k+1][n];
        memset(dp,-1,sizeof dp);
        dp[0][0]=0;
        int ans=0;
        for(int i=1;i<=k;i++){
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    if(dp[i-1][y]!=-1&&(flights[y][x]||x==y)){
                        dp[i][x]=max(dp[i][x],dp[i-1][y]+days[x][i-1]);
                    }
                }
                ans=max(ans,dp[i][x]);
            }
        }
        return ans;
    }
};
