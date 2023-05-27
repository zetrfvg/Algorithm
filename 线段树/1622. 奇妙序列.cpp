/*
题意操作：
1、增加一个元素到尾部，线段树简单扩容即可
2、区间加
3、区间乘
4、单点查询
*/
class Fancy {
public:
    static const int N=1e5+10,mod=1e9+7;
    struct segment{
        long long sum,l,r,mul,add;
    }tr[N*8];
    int idx=0;
    void build(int k,int l,int r){
        tr[k]={0,l,r,1,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(k<<1,l,m);
        build(k<<1|1,m+1,r);
    }
    void pushup(int k){
        tr[k].sum=(tr[k<<1].sum+tr[k<<1|1].sum)%mod;
    }
    void pushdown(int k){
        tr[k<<1].sum=(tr[k].mul*tr[k<<1].sum+((tr[k<<1].r-tr[k<<1].l+1)*tr[k].add)%mod)%mod;
        tr[k<<1|1].sum=(tr[k].mul*tr[k<<1|1].sum+((tr[k<<1|1].r-tr[k<<1|1].l+1)*tr[k].add)%mod)%mod;
        tr[k<<1].mul=(tr[k].mul*tr[k<<1].mul)%mod;
        tr[k<<1|1].mul=(tr[k].mul*tr[k<<1|1].mul)%mod;
        tr[k<<1].add=(tr[k<<1].add*tr[k].mul+tr[k].add)%mod;
        tr[k<<1|1].add=(tr[k<<1|1].add*tr[k].mul+tr[k].add)%mod;
        tr[k].add=0,tr[k].mul=1;
    }
    void add(int k,int l,int r,long long p){
        if(tr[k].l>=l&&tr[k].r<=r){
            tr[k].add=(tr[k].add+p)%mod;
            tr[k].sum=(tr[k].sum+(tr[k].r-tr[k].l+1)*p)%mod;
            return;
        }
        pushdown(k);
        int m=(tr[k].l+tr[k].r)>>1;
        if(l<=m) add(k<<1,l,r,p);
        if(r>m) add(k<<1|1,l,r,p);
        pushup(k);
    }
    void mul(int k,int l,int r,long long p){
        if(tr[k].l>=l&&tr[k].r<=r){
            tr[k].add=(tr[k].add*p)%mod;
            tr[k].mul=(tr[k].mul*p)%mod;
            tr[k].sum=(tr[k].sum*p)%mod;
            return;
        }
        pushdown(k);
        int m=(tr[k].l+tr[k].r)>>1;
        if(l<=m) mul(k<<1,l,r,p);
        if(r>m) mul(k<<1|1,l,r,p);
        pushup(k);
    }
    long long query(int k,int l,int r){
        if(tr[k].l>=l&&tr[k].r<=r){
            return tr[k].sum;
        }
        pushdown(k);
        long long res=0;
        int m=(tr[k].l+tr[k].r)>>1;
        if(l<=m) res=(res+query(k<<1,l,r))%mod;
        if(r>m) res=(res+query(k<<1|1,l,r))%mod;
        return res;
    }
    Fancy(){
        build(1,1,100005);
    }
    
    void append(int val) {
        ++idx;
        add(1,idx,idx,val);
    }
    
    void addAll(int inc) {
        add(1,1,idx,inc);
    }
    
    void multAll(int m) {
        mul(1,1,idx,m);
    }
    
    int getIndex(int _idx){
        _idx++;
        if(_idx>idx) return -1;
        return query(1,_idx,_idx);
    }
};
