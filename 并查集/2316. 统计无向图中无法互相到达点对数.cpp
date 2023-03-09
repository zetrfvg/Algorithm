template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(n+1),siz(n+1),n(_n){
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU<int> dsu(n);
        for(auto p:edges) dsu.unionn(p[0],p[1]);
        long long ans=0,c=n;
        for(int i=0;i<n;i++){
            if(dsu.p[i]==i){
                c-=dsu.siz[i];
                ans+=1LL*dsu.siz[i]*c;
            }
        }
        return ans;
    }
};
