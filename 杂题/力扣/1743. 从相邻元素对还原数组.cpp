/*
建图从一头的端点遍历一遍即可
*/
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,int> deg;
        unordered_map<int,vector<int>> e;
        int s=0;
        for(auto &adj:adjacentPairs){
            ++deg[adj[0]];
            ++deg[adj[1]];
            e[adj[0]].push_back(adj[1]);
            e[adj[1]].push_back(adj[0]);
        }
        for(auto &[x,d]:deg){
            if(d==1){
                s=x;
                break;
            }
        }
        vector<int> ans;
        function<void(int,int)> dfs=[&](int x,int fa){
            ans.push_back(x);
            for(auto y:e[x]){
                if(y==fa) continue;
                dfs(y,x);
            }
        };
        dfs(s,1e9);
        return ans;
    }
};
