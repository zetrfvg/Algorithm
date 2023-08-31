/*
暴力枚举请求，然后再枚举所有限制来判断该请求是否合法
时间复杂度O(nm)
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        DSU<int> dsu(n);
        for(auto &req:requests){
            int x=req[0],y=req[1];
            bool ok=1;
            for(auto &res:restrictions){
                int a=res[0],b=res[1];
                if(dsu.findd(x)==dsu.findd(a)&&dsu.findd(y)==dsu.findd(b)){
                    ok=0;
                    break;
                }
                if(dsu.findd(y)==dsu.findd(a)&&dsu.findd(x)==dsu.findd(b)){
                    ok=0;
                    break;
                }
            }
            if(ok) dsu.unionn(x,y);
            ans.push_back(ok);
        }
        return ans;
    }
};
