/*
按题意用哈希表模拟即可
*/
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                unordered_set<int> l,r;
                for(int x=i-1,y=j-1;x>=0&&y>=0;x--,y--){
                    l.insert(grid[x][y]);
                }
                for(int x=i+1,y=j+1;x<n&&y<m;x++,y++){
                    r.insert(grid[x][y]);
                }
                int a=l.size(),b=r.size();
                ans[i][j]=abs(a-b);
            }
        }
        return ans;
    }
};
