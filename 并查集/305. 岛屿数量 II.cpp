/*
合并周围四个点，每合并一次等价于减少一块陆地
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
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU<int> dsu(n*m);
        vector<vector<int>> vis(m,vector<int>(n));
        int res=0;
        vector<int> ans;
        for(auto &p:positions){
            unordered_set<int> st;
            int x=p[0],y=p[1];
            if(vis[x][y]){
                ans.push_back(res);
                continue;
            }
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0|xx>=m||yy<0||yy>=n||!vis[xx][yy]) continue;
                st.insert(dsu.findd(xx*n+yy));
            }
            for(auto &t:st){
                dsu.unionn(t,x*n+y);
            }
            vis[x][y]=1;
            res+=1-st.size();
            ans.push_back(res);
        }
        return ans;
    }
};
