/*
预处理欧拉筛
首先，如果一个边连接的两个顶点都不是质数，则这两个点用并查集合并
枚举质数顶点，统计经过该顶点的合法路径即可
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
    static const int N=1e5+10;
    int vis[N];
    int prim[N];
    int cnt;

    void Euler(int n){
        for(int i=2;i<=n;i++){
            if(!vis[i]) prim[++cnt]=i;
            for(int j=1;1LL*i*prim[j]<=n;j++){
                vis[i*prim[j]]=1;
                if(i%prim[j]==0) break;
            }
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        Euler(n);
        DSU<int> dsu(n);
        vis[1]=1;
        unordered_map<int,vector<int>> g;
        for(auto e:edges){
            int x=e[0],y=e[1];
            if(!vis[x]&&!vis[y]) continue;
            else if(!vis[x]){
                g[x].push_back(y);
            }else if(!vis[y]){
                g[y].push_back(x);
            }else{
                dsu.unionn(x,y);
            }
        }
        long long ans=0;
        for(auto [h,v]:g){
            long long cur=1;
            for(auto x:v){
                int c=dsu.siz[dsu.findd(x)];
                ans+=1LL*cur*c;
                cur+=c;
            }
        }
        return ans;
    }
};
