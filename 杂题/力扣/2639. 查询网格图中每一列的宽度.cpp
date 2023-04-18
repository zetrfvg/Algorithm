/*
模拟即可
*/
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> ans(m);
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                string s=to_string(grid[i][j]);
                ans[j]=max(ans[j],(int)s.size());
            }
        }
        return ans;
    }
};
