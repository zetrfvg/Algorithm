/*
自底向上递推
定义状态：
dp[i][y1][y2]：第一个机器人在第i行第y1列时，第二个机器人在第i行第y2列时，摘得的最多樱桃
转移方程：
dp[i][y1][y2]=max(dp[i+1][a][b])，其中a∈[y1-1,y1+1]，b∈[y2-1,y2+1]
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[n+1][m][m];
        memset(dp,0,sizeof dp);
        for(int i=n-1;~i;i--){
            for(int y1=0;y1<m;y1++){
                for(int y2=0;y2<m;y2++){
                    int res=0;
                    for(int a=y1-1;a<=y1+1;a++){
                        for(int b=y2-1;b<=y2+1;b++){
                            if(a>=0&&a<m&&b>=0&&b<m){
                                res=max(res,dp[i+1][a][b]+(y1==y2?grid[i][y1]:grid[i][y1]+grid[i][y2]));
                            }
                        }
                    }
                    dp[i][y1][y2]=res;
                }
            }
        }
        return dp[0][0][m-1];
    }
};
