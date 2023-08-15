/*
对所有网格按值排序，每个元素取所在行和所在列的最大值+1即可
*/
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n),col(m);
        vector<array<int,3>> e;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                e.push_back({grid[i][j],i,j});
            }
        }
        sort(e.begin(),e.end());
        for(auto [x,i,j]:e){
            grid[i][j]=max(row[i],col[j])+1;
            row[i]=col[j]=grid[i][j];
        }
        return grid;
    }
};
