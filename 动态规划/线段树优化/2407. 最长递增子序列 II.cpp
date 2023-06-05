/*
考虑nums[i]作为子序列末尾元素时，子序列的最长长度
我们枚举之前所有枚举过的元素nums[j]∈[nums[i]-k,nums[i]-1]，找出这个区间中的元素作为结尾元素时的最大长度，为len
则nums[i]作为子序列末尾元素时，子序列的最长长度为len+1
时间复杂度：O(nk)
观察这个枚举nums[j]，是在区间[nums[i]-k,nums[i]-1]中找一个最大值，因此考虑用线段树优化，能够在对数时间内找到区间最值
时间复杂度：O(nlogn)
*/
class Solution {
public:
    static const int N=1e5+10;
    struct node{
        int l,r,v;
    }tr[N*4];

    void build(int u,int l,int r){
        tr[u]={l,r,0};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void pushup(int u){
        tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
    }

    void modify(int u,int l,int r,int k){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].v=max(tr[u].v,k);
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) modify(u<<1,l,r,k);
        if(r>m) modify(u<<1|1,l,r,k);
        pushup(u);
    }

    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].v;
        }
        int res=0;
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res=max(res,query(u<<1,l,r));
        if(r>m) res=max(res,query(u<<1|1,l,r));
        return res;
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        build(1,0,N-1);
        int ans=0;
        for(auto c:nums){
            int len=query(1,max(0,c-k),max(0,c-1));
            ans=max(ans,++len);
            modify(1,c,c,len);
        }
        return ans;
    }
};
