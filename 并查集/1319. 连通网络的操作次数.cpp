/*
并查集
答案为连通块数量减1
*/
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;
        DSU<int> dsu(n);
        for(int i=0;i<m;i++){
            dsu.unionn(connections[i][0],connections[i][1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=dsu.p[i]==i;
        }
        return ans-1;
    }
};
