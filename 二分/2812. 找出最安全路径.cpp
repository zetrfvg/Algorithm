/*
预处理，多源BFS求出各个单元格到离它最近的小偷的距离
二分答案，判断在答案限制下，起点和终点是否连通，判连通用DSU，DFS，BFS皆可
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
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int maximumSafenessFactor(vector<vector<int>>& g) {
        int l=0,r=1e7;
        int n=g.size(),m=g[0].size();
        if(g[0][0]==1||g[n-1][m-1]==1) return 0;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]){
                    q.push({1,i*m+j});
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [d,p]=q.front();
            q.pop();
            int x=p/m,y=p%m;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||vis[xx][yy]!=-1) continue;
                vis[xx][yy]=d;
                q.push({d+1,xx*m+yy});
            }
        }
        function<bool(int)> check=[&](int mid){
            DSU<int> dsu(n*m);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]<mid) continue;
                    for(int k=0;k<2;k++){
                        int xx=i+dx[k],yy=j+dy[k];
                        if(xx<0||xx>=n||yy<0||yy>=m||vis[xx][yy]<mid) continue;
                        dsu.unionn(i*m+j,xx*m+yy);
                    }
                }
            }
            return dsu.findd(0)==dsu.findd(n*m-1);
        };
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
