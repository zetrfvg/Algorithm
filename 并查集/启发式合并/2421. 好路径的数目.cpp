/*
把点按点权从小到大加入并查集，在维护连通块的时候，我们还需要维护连通块中的最大值个数
当前枚举两个连通块相连，如果最大值不相等，则直接合并即可
如果相等，则把两个连通块最大值的个数累乘，则是这次合并之后新增加的可行路径
依次合并所有点即可

时间复杂度：O(nlogn+nα(n))
*/
template<typename T>
struct DSU{
	int n;
	vector<T> p,siz,cnt,mx;
	DSU(int _n):p(_n+1),cnt(_n+1),mx(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
		if(mx[x]>mx[y]){
		p[y]=x;
	    }else if(mx[x]<mx[y]){
		p[x]=y;
	    }else{
		p[y]=x;
		cnt[x]+=cnt[y];
	    }
	}
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int ans=n;
        DSU<int> dsu(n);
        vector<vector<int>> g(n);
        for(auto p:edges){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        vector<int> ids(n),vis(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return vals[i]<vals[j];
        });
        for(int i=0;i<n;i++){
            dsu.mx[i]=vals[i];
            dsu.cnt[i]=1;
        }
        for(int i=0;i<n;i++){
            int x=ids[i];
            for(auto y:g[x]){
                if(vis[y]){
                    int fx=dsu.findd(x);
                    int fy=dsu.findd(y);
                    if(dsu.mx[fx]==dsu.mx[fy]) ans+=dsu.cnt[fx]*dsu.cnt[fy];
                    dsu.unionn(fx,fy);
                }
            }
            vis[x]=1;
        }
        return ans;
    }
};
