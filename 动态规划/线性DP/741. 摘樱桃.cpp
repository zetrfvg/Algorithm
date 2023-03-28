/*
因为走到终点还需要回到起点，所以可以转化为，有两个人同时向终点走，能够摘得的樱桃数
状态定义：
dp[s][i][j]：两人当前各走了k步，甲在(i,s-i)，乙在(j,s-j)，时获得的最多樱桃数
转移方程：
两人同时向右：由dp[s-1][i][j]转移
甲向下，乙向右：由dp[s-1][i-1][j]转移
甲向右，乙向下：由dp[s-1][i][j-1]转移
两人同时向下：由dp[s-1][i-1][j-1]转移
在四者中取个最大值即可，同时要判断二人是否走到了同一点，避免重复摘樱桃
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int dp[2*n+1][n+1][n+1];
        memset(dp,-0x3f,sizeof dp);
        dp[2][1][1]=grid[0][0];
        for(int s=3;s<=2*n;s++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int x1=i,x2=j,y1=s-i,y2=s-j;
                    if(y1<=0||y1>n||y2<=0||y2>n) continue;
                    int a=grid[x1-1][y1-1],b=grid[x2-1][y2-1];
                    if(a==-1||b==-1) continue;
                    int res=max({dp[s-1][x1][x2],dp[s-1][x1-1][x2],dp[s-1][x1][x2-1],dp[s-1][x1-1][x2-1]})+a;
                    if(x1!=x2) res+=b;
                    dp[s][x1][x2]=res;
                }
            }
        }
        return max(0,dp[2*n][n][n]);
    }
};
