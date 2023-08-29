/*
扫描线+线段树
*/
class Solution {
public:
    static const int N=110;
    struct node{
        int l,r;
        int s,add;
    }tr[N<<2];
    map<int,int> g,f;
    int idx=0;

    void pushup(int u){
        if(tr[u].add){
            tr[u].s=f[tr[u].r+1]-f[tr[u].l];
        }else if(tr[u].l!=tr[u].r){
            tr[u].s=tr[u<<1].s+tr[u<<1|1].s;
        }else{
            tr[u].s=0;
        }
    }

    void build(int u,int l,int r){
        tr[u]={l,r,0,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void modify(int u,int l,int r,int k){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].add+=k;
            pushup(u);
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(u<<1,l,r,k);
        if(r>m) modify(u<<1|1,l,r,k);
        pushup(u);
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<array<int,4>> e;
        for(auto re:rectangles){
            g[re[1]]=1,g[re[3]]=1;
            e.push_back({re[0],re[1],re[3],1});
            e.push_back({re[2],re[1],re[3],-1});
        }
        for(auto &[a,b]:g) b=++idx,f[idx]=a;
        build(1,1,idx);
        sort(e.begin(),e.end());
        const int mod=1e9+7;
        int ans=0;
        for(int i=0;i<e.size();i++){
            if(i) ans=(1LL*ans+1LL*(e[i][0]-e[i-1][0])*tr[1].s%mod)%mod;
            modify(1,g[e[i][1]],g[e[i][2]]-1,e[i][3]);
        }
        return ans;
    }
};
