/*
染色法判定二分图
如果给某个未被染色的节点染上颜色1，对它的邻居DFS并赋给它们颜色2
如果给某个未被染色的节点染上颜色2，对它的邻居DFS并赋给它们颜色1
一旦出现某个访问的节点和当前节点的颜色一致，说明无法划分为二分图
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n);
        bool ans=true;
        function<void(int,int)> dfs=[&](int x,int c){
            color[x]=c;
            for(auto &y:graph[x]){
                if(!color[y]){
                    dfs(y,3-c);
                }else if(color[y]==color[x]){
                    ans=false;
                    return;
                }
            }
        };
        for(int i=0;i<n;i++){
            if(!color[i]){
                dfs(i,1);
            }
        }
        return ans;
    }
};
