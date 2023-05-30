/*
枚举公因数，把含有相同公因数的元素用并查集合并，最后判断整个连通块是否等于n即可
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
    bool canTraverseAllPairs(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,vector<int>> g;
        for(int i=0;i<n;i++){
            if(nums[i]!=1) g[nums[i]].push_back(i);
        }
        DSU<int> dsu(n);
        for(auto &[_,v]:g){
            for(int i=1;i<v.size();i++){
                dsu.unionn(v[i],v[i-1]);
            }
        }
        for(int i=2;i<=mx;i++){
            for(int l=-1,r=-1,p=i;p<=mx;p+=i){
                if(g.count(p)){
                    if(l==-1) l=p;
                    else r=p;
                    if(r!=-1){
                        dsu.unionn(g[l][0],g[r][0]);
                        l=r;
                    }
                }
            }
        }
        return dsu.siz[dsu.findd(0)]==n;
    }
};
