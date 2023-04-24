/*
线段树————单点修改、区间求和
*/
class NumArray {
public:
    static const int N=3e4+10;
    struct node{
        int l,r,sum;
    }tr[N<<2];
    NumArray(vector<int>& nums) {
        build(1,1,nums.size(),nums);
    }
    
    void pushup(int u){
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    }

    void build(int u,int l,int r,vector<int> &a){
        tr[u]={l,r,a[r-1]};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m,a);
        build(u<<1|1,m+1,r,a);
        pushup(u);
    }

    void modify(int u,int l,int r,int k){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].sum=k;
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(u<<1,l,r,k);
        if(r>m) modify(u<<1|1,l,r,k);
        pushup(u);
    }

    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].sum;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        int res=0;
        if(l<=m) res+=query(u<<1,l,r);
        if(r>m) res+=query(u<<1|1,l,r);
        return res;
    }

    void update(int index, int val) {
        modify(1,index+1,index+1,val);
    }
    
    int sumRange(int left, int right) {
        return query(1,left+1,right+1);
    }
};
