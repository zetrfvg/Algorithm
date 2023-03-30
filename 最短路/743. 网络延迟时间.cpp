/*
有向图的单源最短路
*/
//朴素版dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        int idx=0;
        vector<int> e(m+1),w(m+1),ne(m+1),h(n+1),d(n+1,1e9),vis(n+1);
        for(auto p:times){
            int x=p[0],y=p[1],v=p[2];
            e[++idx]=y,w[idx]=v,ne[idx]=h[x],h[x]=idx;
        }
        d[k]=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int i=1;i<=n;i++){
                if(!vis[i]&&(u==-1||d[i]<d[u])){
                    u=i;
                }
            }
            vis[u]=1;
            for(int i=h[u];i;i=ne[i]){
                int y=e[i];
                if(!vis[y]) d[y]=min(d[y],d[u]+w[i]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(d[i]==1e9) return -1;
            ans=max(ans,d[i]);
        }
        return ans;
    }
};

//堆优化dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        int idx=0;
        vector<int> e(m+1),w(m+1),ne(m+1),h(n+1),d(n+1,1e9),vis(n+1);
        for(auto p:times){
            int x=p[0],y=p[1],v=p[2];
            e[++idx]=y,w[idx]=v,ne[idx]=h[x],h[x]=idx;
        }
        d[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            auto [dis,x]=q.top();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=h[x];i;i=ne[i]){
                int y=e[i];
                if(!vis[y]&&d[y]>d[x]+w[i]){
                    d[y]=d[x]+w[i];
                    q.push({d[y],y});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(d[i]==1e9) return -1;
            ans=max(ans,d[i]);
        }
        return ans;
    }
};
