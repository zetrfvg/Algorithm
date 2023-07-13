/*
对元素权值降序排序后进行枚举，对枚举过的相邻元素值用并查集进行合并，直到起终点在同一连通块中，答案则为当前枚举的权值
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
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DSU<int> dsu(n*m);
        vector<tuple<int,int,int>> a;
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a.push_back({-grid[i][j],i,j});
            }
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n*m;i++){
            auto &[w,x,y]=a[i];
            for(int j=0;j<4;j++){
                int xx=x+dx[j],yy=y+dy[j];
                if(xx<0||xx>=n||yy<0||yy>=m||!vis[xx][yy]) continue;
                dsu.unionn(x*m+y,xx*m+yy);
            }
            vis[x][y]=1;
            if(dsu.findd(0)==dsu.findd(n*m-1)) return -w;
        }
        return -1;
    }
};
