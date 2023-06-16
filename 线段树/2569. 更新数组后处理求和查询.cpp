/*
线段树维护nums1，维护nums的和sum
操作1：区间翻转
操作2：sum+(区间[1,n]中的和*p)
操作3：记录此时的sum
*/
class Solution {
public:
    using ll=long long;
    static const int N=1e5+10;
    struct node{
        int l,r;
        ll sum,add;
    }tr[N<<2];
    void pushup(int u){
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    }
    void pushdown(int u){
        if(tr[u].add){
            tr[u<<1].sum=tr[u<<1].r-tr[u<<1].l+1-tr[u<<1].sum;
            tr[u<<1|1].sum=tr[u<<1|1].r-tr[u<<1|1].l+1-tr[u<<1|1].sum;
            tr[u<<1].add^=1;
            tr[u<<1|1].add^=1;
            tr[u].add=0;
        }
    }
    void build(int u,int l,int r,vector<int> &nums1){
        tr[u]={l,r,nums1[l-1],0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m,nums1);
        build(u<<1|1,m+1,r,nums1);
        pushup(u);
    }
    void modify(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].sum=tr[u].r-tr[u].l+1-tr[u].sum;
            tr[u].add^=1;
            return;
        }
        pushdown(u);
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(u<<1,l,r);
        if(r>m) modify(u<<1|1,l,r);
        pushup(u);
    }
    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].sum;
        }
        pushdown(u);
        int res=0;
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res+=query(u<<1,l,r);
        if(r>m) res+=query(u<<1|1,l,r);
        return res;
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        vector<ll> ans;
        ll sum=accumulate(nums2.begin(),nums2.end(),0LL);
        build(1,1,n,nums1);
        for(auto q:queries){
            if(q[0]==1){
                modify(1,q[1]+1,q[2]+1);
            }else if(q[0]==2){
                sum+=1LL*query(1,1,n)*q[1];
            }else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
