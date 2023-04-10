/*
状态定义：
dp[i][j][k]：走k步到达第(i,j)的概率
转移方程：
dp[i][j][k]=Σdp[ii][jj][k-1]。其中，(ii,jj)走一步即可到达(i,j)
*/
class Solution {
public:
    int dx[8]={-1,-1,1,1,-2,-2,2,2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    double knightProbability(int n, int k, int row, int column) {
        double dp[n][n][k+1];
        memset(dp,0,sizeof dp);
        dp[row][column][0]=1;
        for(int p=1;p<=k;p++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int u=0;u<8;u++){
                        int ii=i+dx[u],jj=j+dy[u];
                        if(ii<0||ii>=n||jj<0||jj>=n) continue;
                        dp[i][j][p]+=dp[ii][jj][p-1]/8;
                    }
                }
            }
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j][k];
            }
        }
        return ans;
    }
};
