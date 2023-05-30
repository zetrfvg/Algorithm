/*
我们把相同元素放到一组，用哈希表来统一处理
我们从小到大枚举所有组元素，递推来找到最长的路径
用r(n)来表示各行当前最长的路径是多少，c(m)来表示各列当前最长的路径是多少
枚举元素grid[i][j]，那么达到它的路径就是max(r[i],c[j])+1
处理完一组相等的元素之后，再用到达这些元素的最长路径来更新r[i],c[j]
*/
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,vector<pair<int,int>>> f;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f[mat[i][j]].push_back({i,j});
            }
        }
        int ans=0;
        vector<int> r(n),c(m);
        for(auto &[_,v]:f){
            vector<int> p;
            for(auto &[x,y]:v){
                p.push_back(max(r[x],c[y])+1);
                ans=max(ans,p.back());
            }
            for(int i=0;i<v.size();i++){
                r[v[i].first]=max(r[v[i].first],p[i]);
                c[v[i].second]=max(c[v[i].second],p[i]);
            }
        }
        return ans;
    }
};
