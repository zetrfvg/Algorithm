/*
首先预处理出最小生成树T的和它的权值w，并把最小生成树中的边用一个set来维护
找关键边：
枚举所有边，删除这个边后，能够获得的最小生成树的权值nw是否和w一样，不一样则说明该边为关键边
找伪关键边:
分为T中的边和非T中的边来处理
如果边e[i]在T中，考虑删除这条边，求整个图的最小生成树的权值nw，如果和w一样，说明该边为伪关键边
如果边e[i]不在T中，在求最小生成树之前，先把e[i]加入并查集，再求最小生成树的权值nw，如果和w一样，说明该边为伪关键边
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int w=0,m=edges.size();
        DSU<int> dsu(n);
        vector<vector<int>> ans(2);
        unordered_set<int> st;
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](const auto &a,const auto &b){
            return a[2]<b[2];
        });
        for(int i=0;i<m;i++){
            int x=dsu.findd(edges[i][0]),y=dsu.findd(edges[i][1]);
            if(x!=y){
                w+=edges[i][2];
                dsu.unionn(x,y);
                st.insert(i);
            }
        }
        for(int i=0;i<m;i++){
            DSU<int> u(n);
            int nw=0;
            for(int j=0;j<m;j++){
                if(j==i) continue;
                int x=u.findd(edges[j][0]),y=u.findd(edges[j][1]);
                if(x!=y){
                    nw+=edges[j][2];
                    u.unionn(x,y);
                }
            }
            if(nw!=w) ans[0].push_back(edges[i][3]);
        }
        for(int i=0;i<m;i++){
            if(st.count(i)) continue;
            DSU<int> u(n);
            int nw=edges[i][2];
            u.unionn(edges[i][0],edges[i][1]);
            for(int j=0;j<m;j++){
                int x=u.findd(edges[j][0]),y=u.findd(edges[j][1]);
                if(x!=y){
                    nw+=edges[j][2];
                    u.unionn(x,y);
                }
            }
            if(nw==w) ans[1].push_back(edges[i][3]);
        }
        for(auto i:st){
            DSU<int> u(n);
            int nw=0;
            for(int j=0;j<m;j++){
                if(j==i) continue;
                int x=u.findd(edges[j][0]),y=u.findd(edges[j][1]);
                if(x!=y){
                    nw+=edges[j][2];
                    u.unionn(x,y);
                }
            }
            if(nw==w) ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};
