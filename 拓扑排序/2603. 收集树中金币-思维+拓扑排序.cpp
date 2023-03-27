/*
首先排除无用的点：通过拓扑排序把没有金币的叶子删去，剩下的节点构成一颗子树，这棵树的叶子都有金币
然后再次拓扑排序删除最外面的两层，那么剩下的点一定要走到，因为还要返回原点，那么余下所有的边都会走两边
答案即为剩下的边数*2
*/
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> vis(n),deg(n);
        vector<vector<int>> g(n);
        for(auto p:edges){
            int x=p[0],y=p[1];
            g[x].push_back(y);
            g[y].push_back(x);
            deg[x]++,deg[y]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!coins[i]&&deg[i]==1){
                --deg[i];
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:g[x]){
                if(--deg[y]==1&&!coins[y]){
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]&&deg[i]==1){
                --deg[i];
                vis[i]=1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:g[x]){
                if(--deg[y]==1) vis[y]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) if(!vis[i]) ans++;
        return max((ans-1)*2,0);
    }
};
