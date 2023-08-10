/*
模拟验证
*/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        auto check=[&](int x,int y){
            vector<int> f(10);
            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    if(grid[i][j]==0||grid[i][j]>9) return false;
                    if(++f[grid[i][j]]>1) return false;
                }
            }
            int sum=grid[x][y]+grid[x][y+1]+grid[x][y+2];
            if(sum!=grid[x+1][y]+grid[x+1][y+1]+grid[x+1][y+2]) return false;
            if(sum!=grid[x+2][y]+grid[x+2][y+1]+grid[x+2][y+2]) return false;
            if(sum!=grid[x][y]+grid[x+1][y]+grid[x+2][y]) return false;
            if(sum!=grid[x][y+1]+grid[x+1][y+1]+grid[x+2][y+1]) return false;
            if(sum!=grid[x][y+2]+grid[x+1][y+2]+grid[x+2][y+2]) return false;
            if(sum!=grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]) return false;
            if(sum!=grid[x+2][y]+grid[x+1][y+1]+grid[x][y+2]) return false;
            return true;
        };
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans+=check(i,j);
            }
        }
        return ans;
    }
};
