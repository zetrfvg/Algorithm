/*
从大到小考虑元素，把枚举过的元素，相邻的用并查集合并，枚举到nums[i]>threshold/k时即可
其中k也可用并查集来维护
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
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        DSU<int> dsu(n);
        vector<int> ids(n),vis(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return nums[i]>nums[j];
        });
        for(int i=0;i<n;i++){
            int j=ids[i];
            if(j&&vis[j-1]) dsu.unionn(j,j-1);
            if(j<n-1&&vis[j+1]) dsu.unionn(j,j+1);
            if(threshold<1LL*nums[j]*dsu.siz[dsu.findd(j)]) return dsu.siz[dsu.findd(j)];
            vis[j]=1;
        }
        return -1;
    }
};
