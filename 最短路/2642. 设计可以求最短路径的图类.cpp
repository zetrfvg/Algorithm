/*
dijkstra模板题
*/
//朴素dijkstra
class Graph {
public:
    vector<vector<pair<int,int>>> e;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        e.resize(n);
        for(auto &p:edges){
            e[p[0]].push_back({p[1],p[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        e[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> vis(n),dis(n,1e9);
        dis[node1]=0;
        for(int i=0;i<n;i++){
            int x=-1;
            for(int j=0;j<n;j++){
                if(!vis[j]&&(x==-1||dis[x]>dis[j])) x=j;
            }
            vis[x]=1;
            for(auto [y,w]:e[x]){
                if(!vis[y]) dis[y]=min(dis[y],dis[x]+w);
            }
        }
        return dis[node2]==(int)1e9?-1:dis[node2];
    }
};
//堆优化dijkstra
class Graph {
public:
    vector<vector<pair<int,int>>> e;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        e.resize(n);
        for(auto &p:edges){
            e[p[0]].push_back({p[1],p[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        e[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> vis(n),dis(n,1e9);
        dis[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,node1});
        while(!q.empty()){
            auto [d,x]=q.top();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(auto [y,w]:e[x]){
                if(!vis[y]&&dis[y]>dis[x]+w){
                    dis[y]=dis[x]+w;
                    q.push({dis[y],y});
                }
            }
        }
        return dis[node2]==(int)1e9?-1:dis[node2];
    }
};
