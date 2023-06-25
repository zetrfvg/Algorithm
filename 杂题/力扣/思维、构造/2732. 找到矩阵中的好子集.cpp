/*
结论：至多可以只考虑两行配在一起构成一个好子集
*/
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        unordered_map<int,int> g;
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<m;j++){
                t|=(grid[i][j]<<j);
            }
            g[t]=i;
        }
        if(g.count(0)) return {g[0]};
        for(auto &[a,b]:g){
            for(auto &[c,d]:g){
                if(!(a&c)) return {min(b,d),max(b,d)};
            }
        }
        return {};
    }
};
