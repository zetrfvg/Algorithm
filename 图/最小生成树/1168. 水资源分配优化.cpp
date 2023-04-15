/*
将0号点视作水井
wells数组相当于每个点向0号点连边的代价
问题转化为最小生成树
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0;i<n;i++){
            pipes.push_back({0,i+1,wells[i]});
        }
        sort(pipes.begin(),pipes.end(),[](const auto &a,const auto &b){
            return a[2]<b[2];
        });
        DSU<int> dsu(n);
        int ans=0;
        for(auto &p:pipes){
            int x=dsu.findd(p[0]),y=dsu.findd(p[1]);
            if(x!=y){
                dsu.unionn(x,y);
                ans+=p[2];
            }
        }
        return ans;
    }
};
