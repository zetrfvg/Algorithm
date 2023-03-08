template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int n):p(n+1),siz(n+1){
		iota(p.begin(),p.end(),0);
		for(int i=0;i<n+1;i++) siz[i]=1;
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        DSU<int> dsu(n);
        for(auto t:edges) dsu.unionn(t[0],t[1]);
        return dsu.findd(source)==dsu.findd(destination);
    }
};
