/*
朴素dijkstra解法
*/
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<vector<array<int,2>>> e(n);
        for(auto ed:edges) e[ed[0]].push_back({ed[1],ed[2]});
        unordered_set<int> st(marked.begin(),marked.end());
        vector<int> d(n,1e9),vis(n);
        d[s]=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!vis[j]&&(u==-1||d[j]<d[u])) u=j;
            }
            if(u==-1||d[u]==1e9) break;
            if(st.count(u)) return d[u];
            vis[u]=1;
            for(auto [y,w]:e[u]) d[y]=min(d[y],d[u]+w);
        }
        return -1;
    }
};
