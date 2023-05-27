/*
枚举最大公因数[threshold+1,n]
对于每个公因数g，我们依次连边(g,g*2)、(g*2,g*3)、(g*3,g*4)···
维护连通性，用并查集即可
时间复杂度：调和级数复杂度，调和级数增上趋势是对数级的，整个算法等价于O(nlogn)
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU<int> dsu(n);
        for(int i=threshold+1;i<=n;i++){
            for(int x=i,y=i*2;y<=n;x+=i,y+=i){
                dsu.unionn(x,y);
            }
        }
        vector<bool> ans;
        for(auto &p:queries){
            ans.push_back(dsu.findd(p[0])==dsu.findd(p[1]));
        }
        return ans;
    }
};
