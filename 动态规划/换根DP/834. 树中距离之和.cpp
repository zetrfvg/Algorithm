/*
第一遍dfs求出各个节点作为根的子树的大小，并记录子树中所有节点到它的距离之和
第二遍dfs传入四个参数：x-当前节点；fa-x的父节点；cnt-以x为根结点的子树之外的节点数量；sum-以x为根结点的子树之外的节点到它的距离
*/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> sz(n,1),dis(n);
        vector<vector<int>> e(n);
        vector<int> ans(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        function<void(int,int)> dfs1=[&](int x,int fa){
            for(auto &y:e[x]){
                if(y==fa) continue;
                dfs1(y,x);
                dis[x]+=dis[y]+sz[y];
                sz[x]+=sz[y];
            }
        };
        function<void(int,int,int,int)> dfs2=[&](int x,int fa,int cnt,int sum){
            ans[x]=dis[x]+sum;
            for(auto &y:e[x]){
                if(y==fa) continue;
                dfs2(y,x,cnt+sz[x]-sz[y],sum+dis[x]-dis[y]-sz[y]+cnt+sz[x]-sz[y]);
            }
        };
        dfs1(0,-1);
        dfs2(0,-1,0,0);
        return ans;
    }
};
