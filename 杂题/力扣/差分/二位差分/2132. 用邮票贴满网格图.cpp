/*
二维差分与二维前缀和
*/
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> pre(n+1,vector<int>(m+1)),dif(n+2,vector<int>(m+2));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]+grid[i][j]-pre[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ii=i+stampHeight-1,jj=j+stampWidth-1;
                if(ii>n||jj>m||grid[i-1][j-1]) continue;
                if(pre[ii][jj]-pre[ii][j-1]-pre[i-1][jj]+pre[i-1][j-1]==0){
                    dif[i][j]++,dif[i][jj+1]--,dif[ii+1][j]--,dif[ii+1][jj+1]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dif[i][j]+=dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
                if(!dif[i][j]&&!grid[i-1][j-1]) return false;
            }
        }
        return true;
    }
};
