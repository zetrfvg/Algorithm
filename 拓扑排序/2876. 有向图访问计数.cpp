/*
原图为基环树（森林）
拓扑排序找出所有的环，每个环上的点可达的点即为该点所在环的环长，这里用并查集来计算环上的点数
然后从反图去递推出所有不在环上的点能够到达的点数
*/
template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(_n+1),siz(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
		for(int i=0;i<=n;i++) siz[i]=1;
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
	}
};
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& e) {
        int n=e.size();
        vector<int> deg(n);
        vector<vector<int>> ne(n);
        DSU<int> dsu(n);
        for(int i=0;i<n;i++){
            deg[e[i]]++;
            dsu.unionn(i,e[i]);
            ne[e[i]].push_back(i);
        }
        vector<int> vis(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!deg[i]) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            dsu.siz[dsu.findd(x)]--;
            vis[x]=1;
            if(!--deg[e[x]]) q.push(e[x]);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++) if(!vis[i]) ans[i]=dsu.siz[dsu.findd(i)];
        function<void(int)> dfs=[&](int x){
            for(auto y:ne[x]){
                if(ans[y]!=-1) continue;
                ans[y]=ans[x]+1;
                dfs(y);
            }
        };
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
        return ans;
    }
};
