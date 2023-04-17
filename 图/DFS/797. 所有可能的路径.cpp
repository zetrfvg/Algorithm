/*
简单搜索即可
*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> res,vis(n);
        function<void(int)> dfs=[&](int x){
            res.push_back(x);
            vis[x]=1;
            if(x==n-1){
                ans.push_back(res);
            }else{
                for(auto y:graph[x]){
                    if(!vis[y]){
                        dfs(y);
                    }
                }
            }
            vis[x]=0;
            res.pop_back();
        };
        dfs(0);
        return ans;
    }
};
