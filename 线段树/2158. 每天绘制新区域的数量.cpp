/*
线段树维护已经绘制过的区间，每次绘制区间[l,r]，先查询[l,r]中有多少点被画了，统计答案后，将该区间加入线段树
*/
class Solution {
public:
    static const int N=5e4+50;
    struct node{
        int l,r,s,add;
    }tr[N<<2];

    void pushup(int u){
        tr[u].s=tr[u<<1].s+tr[u<<1|1].s;
    }

    void pushdown(int u){
        if(tr[u].add){
            tr[u<<1].add|=tr[u].add;
            tr[u<<1].s=(tr[u<<1].r-tr[u<<1].l+1);
            tr[u<<1|1].add|=tr[u].add;
            tr[u<<1|1].s=(tr[u<<1|1].r-tr[u<<1|1].l+1);
            tr[u].add=0;
        }
    }

    void build(int u,int l,int r){
        tr[u]={l,r,0,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void modify(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].s=tr[u].r-tr[u].l+1;
            tr[u].add=1;
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        pushdown(u);
        if(l<=m) modify(u<<1,l,r);
        if(r>m) modify(u<<1|1,l,r);
        pushup(u);
    }

    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].s;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        int res=0;
        pushdown(u);
        if(l<=m) res+=query(u<<1,l,r);
        if(r>m) res+=query(u<<1|1,l,r);
        return res;
    }

    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n=paint.size();
        build(1,0,N-10);
        vector<int> ans;
        for(auto p:paint){
            p[1]--;
            int len=query(1,p[0],p[1]);
            ans.push_back(p[1]-p[0]+1-len);
            modify(1,p[0],p[1]);
        }
        return ans;
    }
};
