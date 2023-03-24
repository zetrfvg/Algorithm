/*
在四个方向上分别DP，统计每个空位各能轰炸多少敌人
取最大值即可
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int s=0,ans=0;
        for(int i=0;i<n;i++){
            s=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='W') s=0;
                else if(grid[i][j]=='E') s++;
                dp[i][j]+=s;
            }
        }
        s=0;
        for(int i=0;i<n;i++){
            s=0;
            for(int j=m-1;~j;j--){
                if(grid[i][j]=='W') s=0;
                else if(grid[i][j]=='E') s++;
                dp[i][j]+=s;
            }
        }
        s=0;
        for(int j=0;j<m;j++){
            s=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]=='W') s=0;
                else if(grid[i][j]=='E') s++;
                dp[i][j]+=s;
            }
        }
        s=0;
        for(int j=0;j<m;j++){
            s=0;
            for(int i=n-1;~i;i--){
                if(grid[i][j]=='W') s=0;
                else if(grid[i][j]=='E') s++;
                dp[i][j]+=s;
                if(grid[i][j]=='0') ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
