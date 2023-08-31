/*
求1所在连通块中路径最小的权值
*/
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<array<int,2>>> e(n+1);
        for(auto r:roads){
            e[r[0]].push_back({r[1],r[2]});
            e[r[1]].push_back({r[0],r[2]});
        }
        vector<int> vis(n+1);
        int ans=1e9;
        function<void(int)> dfs=[&](int x){
            vis[x]=1;
            for(auto [y,w]:e[x]){
                ans=min(ans,w);
                if(!vis[y]){
                    dfs(y);
                }
            }
        };
        dfs(1);
        return ans;
    }
};
