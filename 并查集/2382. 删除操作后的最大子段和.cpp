/*
并查集逆序维护集合元素和即可
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
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n=nums.size();
        vector<long long> ans(n),val(n);
        DSU<int> dsu(n);
        vector<int> vis(n);
        long long cur=0;
        for(int i=n-1;~i;i--){
            ans[i]=cur;
            int j=removeQueries[i];
            val[j]=nums[j];
            if(j&&vis[j-1]) val[j]+=val[dsu.findd(j-1)],dsu.unionn(j,j-1);
            if(j<n-1&&vis[j+1]) val[j]+=val[dsu.findd(j+1)],dsu.unionn(j,j+1);
            vis[j]=1;
            cur=max(cur,val[dsu.findd(j)]=val[j]);
        }
        return ans;
    }
};
