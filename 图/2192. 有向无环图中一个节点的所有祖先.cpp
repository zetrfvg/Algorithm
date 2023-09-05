/*
暴力枚举各个点x可以到达的子孙节点
*/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n),e(n);
        for(auto ed:edges){
            e[ed[0]].push_back(ed[1]);
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            function<void(int,int)> dfs=[&](int ancestor,int x){
                vis[x]=1;
                if(x!=ancestor) ans[x].push_back(ancestor);
                for(auto y:e[x]) if(!vis[y]) dfs(ancestor,y);
            };
            dfs(i,i);
        }
        return ans;
    }
};
