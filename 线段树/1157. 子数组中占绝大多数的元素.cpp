/*
摩尔投票+线段树
线段树不能维护众数，这里可以维护绝对众数，用摩尔投票的方式来合并子区间的信息，得到完整信息
线段树找到区间中的绝对众数后，用二分的方法查询区间内该元素的个数是否大于threshold
*/
class MajorityChecker {
public:
    const int N=2e4+10;
    struct node{
        int val,cnt,l,r;
        node operator+(const node &b) const{
            node res;
            res.l=min(l,b.l);
            res.r=max(r,b.r);
            if(val==b.val){
                res.val=val;
                res.cnt=cnt+b.cnt;
            }else if(cnt>b.cnt){
                res.val=val;
                res.cnt=cnt-b.cnt;
            }else{
                res.val=b.val;
                res.cnt=b.cnt-cnt;
            }
            return res;
        }
    };
    vector<node> tr;
    vector<vector<int>> s;
    void pushup(int u){
        tr[u]=tr[u<<1]+tr[u<<1|1];
    }
    void build(int u,int l,int r,vector<int> &arr){
        if(l==r){
            tr[u]={arr[l-1],1,l,r};
            return;
        }
        int m=(l+r)>>1;
        build(u<<1,l,m,arr);
        build(u<<1|1,m+1,r,arr);
        pushup(u);
    }
    MajorityChecker(vector<int>& arr) {
        tr.resize(N*4);
        s.resize(N);
        build(1,1,arr.size(),arr);
        for(int i=0;i<arr.size();i++){
            s[arr[i]].push_back(i);
        }
    }
    node queryy(int u,int l,int r){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u];
        }
        node res={0,0,0,0};
        int m=(tr[u].l+tr[u].r)>>1;
        if(l<=m) res=res+queryy(u<<1,l,r);
        if(r>m) res=res+queryy(u<<1|1,l,r);
        return res;
    }
    int query(int left, int right, int threshold) {
        int ans=queryy(1,left+1,right+1).val;
        if(upper_bound(s[ans].begin(),s[ans].end(),right)-lower_bound(s[ans].begin(),s[ans].end(),left)<threshold) ans=-1;
        return ans;
    }
};
