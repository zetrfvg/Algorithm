/*
线段树维护区间与
双指针枚举，我们需要枚举最接近的大于等于target的值和最接近的小于等于target的值
因为区间与这个东西如果固定左端点，向右扩展一定是单调递减的
枚举大于等于target的值：枚举右端点，如果区间与小于target则移动左端点
枚举小于等于target的值：枚举左端点，如果区间与大于target则移动右端点
*/
class Solution {
public:
    static const int N=1e5+10;
    struct node{
        int l,r,s;
    }tr[N<<2];

    void pushup(int u){
        tr[u].s=tr[u<<1].s&tr[u<<1|1].s;
    }

    void build(int u,int l,int r,vector<int>& arr){
        tr[u]={l,r,0};
        if(l==r){
            tr[u].s=arr[l-1];
            return;
        }
        int m=(l+r)>>1;
        build(u<<1,l,m,arr);
        build(u<<1|1,m+1,r,arr);
        pushup(u);
    }

    int query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u].s;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        int res=INT_MAX;
        if(l<=m) res&=query(u<<1,l,r);
        if(r>m) res&=query(u<<1|1,l,r);
        return res;
    }

    int closestToTarget(vector<int>& arr, int target) {
        int n=arr.size();
        build(1,1,n,arr);
        int ans=INT_MAX;
        for(int l=0,r=0;r<n;r++){
            while(l<r&&query(1,l+1,r+1)<target) l++;
            if(l==r&&arr[l]<target) continue;
            ans=min(ans,query(1,l+1,r+1)-target);
        }
        for(int l=0,r=0;l<n;l++){
            while(r<n&&query(1,l+1,r+1)>target) r++;
            if(query(1,l+1,r+1)>target) continue;
            ans=min(ans,target-query(1,l+1,r+1));
        }
        return ans;
    }
};
