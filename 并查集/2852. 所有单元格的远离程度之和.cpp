/*
并查集实现，题目不难，较为繁琐
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
    using ll=long long;
    int dx[2]={0,-1};
    int dy[2]={-1,0};
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<ll> val(n*m);
        ll sum=0;
        DSU<int> dsu(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) continue;
                val[i*m+j]=grid[i][j];
                sum+=grid[i][j];
                for(int k=0;k<2;k++){
                    int ii=i+dx[k],jj=j+dy[k];
                    if(ii<0||jj<0||grid[ii][jj]==-1) continue;
                    if(dsu.findd(ii*m+jj)==dsu.findd(i*m+j)) continue;
                    ll s=val[dsu.findd(ii*m+jj)]+val[dsu.findd(i*m+j)];
                    dsu.unionn(ii*m+jj,i*m+j);
                    val[dsu.findd(i*m+j)]=s;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) continue;
                ans+=sum-val[dsu.findd(i*m+j)];
            }
        }
        return ans;
    }
};
