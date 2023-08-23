/*
并查集
值域为1e5，因此可以将数字x与其所有的因子在并查集中合并，最后统计各个集合中的元素数量即可
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
    int largestComponentSize(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        DSU<int> dsu(m);
        vector<int> cnt(m+1);
        for(auto x:nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    dsu.unionn(x,i);
                    dsu.unionn(x,x/i);
                }
            }
        }
        int ans=0;
        for(auto x:nums){
            ans=max(ans,++cnt[dsu.findd(x)]);
        }
        return ans;
    }
};
