class MyCalendar {
public:
    static const int N=1e3+10;
    struct node{
        int l,r,sum,add,ls,rs;
    }tr[N<<6];
    int cnt=0;
    void create(int &u,int l,int r){
        u=++cnt;
        tr[u]={l,r,0,0,0,0};
    }
    void pushup(int u){
        int m=(tr[u].l+tr[u].r)>>1;
        if(!tr[u].ls) create(tr[u].ls,tr[u].l,m);
        if(!tr[u].rs) create(tr[u].rs,m+1,tr[u].r);
        tr[u].sum=tr[tr[u].ls].sum+tr[tr[u].rs].sum;
    }
    void pushdown(int u){
        int m=(tr[u].l+tr[u].r)>>1;
        if(!tr[u].ls) create(tr[u].ls,tr[u].l,m);
        if(!tr[u].rs) create(tr[u].rs,m+1,tr[u].r);
        int ls=tr[u].ls,rs=tr[u].rs;
        if(tr[u].add){
            tr[ls].sum+=tr[u].add*(tr[ls].r-tr[ls].l+1);
            tr[ls].add+=tr[u].add;
            tr[rs].sum+=tr[u].add*(tr[rs].r-tr[rs].l+1);
            tr[rs].add+=tr[u].add;
            tr[u].add=0;
        }
    }
    void modify(int u,int l,int r,int k){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].sum=k*(tr[u].r-tr[u].l+1);
            tr[u].add+=k;
            return;
        }
        pushdown(u);
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(tr[u].ls,l,r,k);
        if(r>m) modify(tr[u].rs,l,r,k);
        pushup(u);
    }
    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].sum;
        }
        pushdown(u);
        int res=0;
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res+=query(tr[u].ls,l,r);
        if(r>m) res+=query(tr[u].rs,l,r);
        pushup(u);
        return res;
    }
    MyCalendar() {
        int root=0;
        create(root,0,(int)1e9);
    }
    
    bool book(int start, int end) {
        if(query(1,start,end-1)) return false;
        modify(1,start,end-1,1);
        return true;
    }
};
