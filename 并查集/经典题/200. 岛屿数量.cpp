template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(n+1),siz(n+1),n(_n){
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
    int dx[2]={0,-1};
    int dy[2]={-1,0};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DSU<int> dsu(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    for(int k=0;k<2;k++){
                        int x=i+dx[k],y=j+dy[k];
                        if(x<0||y<0||grid[x][y]=='0') continue;
                        dsu.unionn(i*m+j,x*m+y);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*m;i++) if(grid[i/m][i%m]=='1'&&dsu.p[i]==i) ans++;
        return ans;
    }
};
