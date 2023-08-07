/*
三种操作：
1、单点加
2、子树加
3、子树和查询
在整个树的dfs序上，建立线段树，子树加变为区间加，子树和查询变为区间和查询
*/
class Solution {
public:
    using ll=long long;
    static const int mod=1e9+7,N=5e4+10;
    vector<int> e[N];
    int L[N],R[N];
    int idx=0;
    struct node{
        int l,r;
        ll sum,add;
    }tr[N<<2];
    
    function<void(int)> dfs=[&](int x){
        L[x]=++idx;
        for(auto y:e[x]) dfs(y);
        R[x]=idx;
    };
    
    void build(int u,int l,int r){
        tr[u]={l,r,0,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void pushup(int u){
        tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod;
    }

    void pushdown(int u){
        if(tr[u].add){
            tr[u<<1].sum=((tr[u<<1].r-tr[u<<1].l+1)*tr[u].add+tr[u<<1].sum)%mod;
            tr[u<<1].add=(tr[u<<1].add+tr[u].add)%mod;
            tr[u<<1|1].sum=((tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add+tr[u<<1|1].sum)%mod;
            tr[u<<1|1].add=(tr[u<<1|1].add+tr[u].add)%mod;
            tr[u].add=0;
        }
    }

    void modify(int u,int l,int r,ll k){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].sum=((tr[u].r-tr[u].l+1)*k+tr[u].sum)%mod;
            tr[u].add=(tr[u].add+k)%mod;
            return;
        }
        pushdown(u);
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(u<<1,l,r,k);
        if(r>m) modify(u<<1|1,l,r,k);
        pushup(u);
    }

    ll query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].sum;
        }
        pushdown(u);
        ll res=0;
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res=(res+query(u<<1,l,r))%mod;
        if(r>m) res=(res+query(u<<1|1,l,r))%mod;
        pushup(u);
        return res;
    }

    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        for(int i=0;i<n-1;i++){
            e[leadership[i][0]].push_back(leadership[i][1]);
        }
        dfs(1);
        build(1,1,n);
        vector<int> ans;
        for(auto op:operations){
            if(op[0]==1) modify(1,L[op[1]],L[op[1]],op[2]);
            else if(op[0]==2) modify(1,L[op[1]],R[op[1]],op[2]);
            else ans.push_back(query(1,L[op[1]],R[op[1]]));
        }
        return ans;
    }
};
