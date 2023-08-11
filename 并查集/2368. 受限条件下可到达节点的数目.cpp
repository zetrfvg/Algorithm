/*
如果一条边连接的两个节点都不受限的话，在并查集中合并即可，否则不合并，最后返回0结点所在的连通块大小即可
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        DSU<int> dsu(n);
        unordered_set<int> st(restricted.begin(),restricted.end());
        for(auto e:edges){
            if(!st.count(e[0])&&!st.count(e[1])) dsu.unionn(e[0],e[1]);
        }
        return dsu.siz[dsu.findd(0)];
    }
};
