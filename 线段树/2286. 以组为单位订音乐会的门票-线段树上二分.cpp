/*
线段树上二分模板
*/
class BookMyShow {
public:
    using ll=long long;
    static const int N=5e4+10;
    struct node{
        int l,r;
        ll mn,s;
    }tr[N<<2];

    void pushup(int u){
        tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
        tr[u].s=tr[u<<1].s+tr[u<<1|1].s;
    }

    void build(int u,int l,int r){
        tr[u]={l,r,0,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void modify(int u,int idx,int k){
        if(tr[u].l==tr[u].r){
            tr[u].mn+=k;
            tr[u].s+=k;
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(idx<=m) modify(u<<1,idx,k);
        else modify(u<<1|1,idx,k);
        pushup(u);
    }

    ll query_sum(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r) return tr[u].s;
        ll res=0;
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res+=query_sum(u<<1,l,r);
        if(r>m) res+=query_sum(u<<1|1,l,r);
        return res;
    }

    int query_idx(int u,int r,int k){
        if(tr[u].mn>k) return 0;//该区间中满足条件的一排，返回0
        if(tr[u].l==tr[u].r) return tr[u].l;//满足条件能够坐下的最小的一排
        int m=(tr[u].l+tr[u].r)>>1;
        if(tr[u<<1].mn<=k) return query_idx(u<<1,r,k);//如果左区间中的最小值小于k，则优先递归左区间
        if(m<r) return query_idx(u<<1|1,r,k);//否者只能递归右区间
        return 0;
    }

    int cap;//容量
    BookMyShow(int n, int m) {
        build(1,1,n);//建树
        cap=m;
    }
    
    vector<int> gather(int k, int maxRow) {
        int i=query_idx(1,maxRow+1,cap-k);//找到已坐人数不多于cap-k的最小那一排
        if(!i) return {};//前maxRow排中不存在可以坐下k个人的一排
        int seats=query_sum(1,i,i);//该排已坐的座位数，如果返回值是x，说明应该从当前排的第x座位开始坐
        modify(1,i,k);//给该排坐的人数加上k个
        return {i-1,seats};
    }
    
    bool scatter(int k, int maxRow) {
        if(1LL*(maxRow+1)*cap-query_sum(1,1,maxRow+1)<k) return false;//前maxRow的位置余量不足k个
        for(int i=query_idx(1,maxRow+1,cap-1);;i++){//从未坐满的最小的一排开始坐人
            int rest=cap-query_sum(1,i,i);//座位余量
            if(k<=rest){//座位余量比要安排座位的人数多
                modify(1,i,k);//该排座位减去k个
                return true;//全部安排完毕
            }
            k-=rest;//座位余量比要安排座位的人数少，先安排rest个人到该排就坐，于是还剩k-rest个要安排
            modify(1,i,rest);//该排座位减去rest个，已经满员
        }
    }
};
