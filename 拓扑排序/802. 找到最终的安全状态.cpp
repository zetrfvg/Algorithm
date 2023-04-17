/*
将原图中的所有边反向建图
原来出度为0的点是终端节点，反图中入度为0的点则为终端节点
同时，反图中终端节点指向的节点(原图中只指向终端节点的节点)，其中那些不在环上的，必然是安全节点，因此对反图拓扑排序即可
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> e(n);
        vector<int> deg(n),vis(n),ans;
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                e[j].push_back(i);
            }
            deg[i]=graph[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!deg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            vis[x]=1;
            for(auto y:e[x]){
                if(!--deg[y]){
                    q.push(y);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
