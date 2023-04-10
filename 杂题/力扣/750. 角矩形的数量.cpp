/*
矩阵中的元素要么是1要么是0，考虑用bitset来暴力枚举，第i行的状态用r[i]来表示
考虑元素grid[i][j]=1，枚举i之前的所有行u，对r[i]和r[u]取交之后集合中1的个数就是以grid[i][j]为右下角端点的矩形个数
累加答案之后，令r[i][j]=1，继续枚举即可
*/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        bitset<205> r[n],v;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int u=i-1;u>=0;u--){
                        if(grid[u][j]){
                            v=r[u]&r[i];
                            ans+=v.count();
                        }
                    }
                    r[i][j]=1;
                }
            }
        }
        return ans;
    }
};
