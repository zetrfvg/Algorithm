/*
状态定义：
dp[i][j]：走到第i格第j列的最小和
转移方程：
dp[i][j]=min(dp[i-1][k])+grid[i][j]，其中k∈[0,j)∪(j,n-1]
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int fi=-1,se=-1;
        for(int i=0;i<n;i++){
            int fii=-1,see=-1;
            for(int j=0;j<n;j++){
                if(!i){
                    if(fii==-1||grid[i][fii]>grid[i][j]){
                        see=fii,fii=j;
                    }else if(see==-1||grid[i][see]>grid[i][j]){
                        see=j;
                    }
                }else{
                    if(j==fi) grid[i][j]+=grid[i-1][se];
                    else grid[i][j]+=grid[i-1][fi];
                    if(fii==-1||grid[i][fii]>grid[i][j]){
                        see=fii,fii=j;
                    }else if(see==-1||grid[i][see]>grid[i][j]){
                        see=j;
                    }
                }
            }
            fi=fii,se=see;
        }
        return *min_element(grid.back().begin(),grid.back().end());
    }
};
