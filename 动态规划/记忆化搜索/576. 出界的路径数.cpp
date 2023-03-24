/*
定义状态：
dp[i][j]：走cnt步后到达第i行第j列的方案数
状态转移：
对于(i,j)相邻的四个格子，如果出界，则累加答案即可，否则，走到相邻格子的方案数应当加上走到(i,j)的方案数
转移完毕之后，须把dp[i][j]置0，以便下次走cnt+2步时不会累加上走cnt步的方案数
也可以对dp多开一个维度来记录走了多少步的状态
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        const int mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(m));
        dp[startRow][startColumn]=1;
        queue<int> q;
        int ans=0;
        q.push(startRow*m+startColumn);
        while(maxMove--){
            int sz=q.size();
            while(sz--){
                auto pos=q.front();
                q.pop();
                int x=pos/m,y=pos%m;
                if(!dp[x][y]) continue;
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m) ans=(ans+dp[x][y])%mod;
                    else{
                        dp[xx][yy]=(dp[xx][yy]+dp[x][y])%mod;
                        q.push(xx*m+yy);
                    }
                }
                dp[x][y]=0;
            }
        }
        return ans;
    }
};
