/*
一个点连通块的权值为grid[i][j]，合并连通块之后取权值和最大的那个
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
    int dx[2]={0,-1};
    int dy[2]={-1,0};
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DSU<int> dsu(n*m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dsu.siz[i*m+j]=grid[i][j];
                if(grid[i][j]){
                    for(int k=0;k<2;k++){
                        int ii=i+dx[k],jj=j+dy[k];
                        if(ii<0||jj<0||!grid[ii][jj]) continue;
                        dsu.unionn(i*m+j,ii*m+jj);
                    }
                    ans=max(ans,dsu.siz[dsu.findd(i*m+j)]);
                }
            }
        }
        return ans;
    }
};
