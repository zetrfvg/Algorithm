/*
暴力枚举所有的点对是否属于同一集合，用并查集合并，最后统计答案即可
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
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        DSU<int> dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(categoryHandler->haveSameCategory(i,j)) dsu.unionn(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) ans+=dsu.p[i]==i;
        return ans;
    }
};
