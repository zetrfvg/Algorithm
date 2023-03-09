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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU<int> dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) dsu.unionn(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) if(dsu.p[i]==i) ans++;
        return ans;
    }
};
