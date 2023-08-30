/*
线段树结点信息：区间左端点l，区间右端点r，区间中最长连续重复子串长度mx，前缀的重复长度pre，后缀的重复长度suf
合并操作：
对于结点u，记左儿子为left，右儿子为right
一般地有：
1、u.pre=left.pre
2、u.suf=right.suf
3、u.mx=max(left.mx,right.mx)
不一般(即left.r位置上的字符和right.l位置上的字符相等时)：
1、if(left.mx==left.r-left.l+1) u.pre=left.mx+right.pre
2、if(right.mx==right.r-right.l+1) u.suf=left.suf+right.mx
3、u.mx=max(u.mx,left.suf+right.pre)
*/
class Solution {
public:
    static const int N=1e5+10;
    struct node{
        int l,r;
        int pre,suf,mx;
    }tr[N<<2];
    string cur;

    void build(int u,int l,int r){
        tr[u]={l,r,1,1,1};
        if(l==r) return;
        int m=(l+r)>>1;
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
    }

    void modify(int u,int idx,char ch){
        if(tr[u].l==idx&&tr[u].r==idx){
            cur[idx-1]=ch;
            return;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(idx<=m) modify(u<<1,idx,ch);
        else modify(u<<1|1,idx,ch);
        pushup(u);
    }

    void pushup(int u){
        auto l=tr[u<<1],r=tr[u<<1|1];
        int ll=l.r-l.l+1,rr=r.r-r.l+1;
        tr[u].pre=l.pre,tr[u].suf=r.suf;
        tr[u].mx=max(l.mx,r.mx);
        if(cur[l.r-1]==cur[r.l-1]){
            if(l.pre==ll) tr[u].pre=ll+r.pre;
            if(r.suf==rr) tr[u].suf=rr+l.suf;
            tr[u].mx=max(tr[u].mx,l.suf+r.pre);
        }
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        cur=s;
        int k=queryCharacters.size(),n=s.size();
        vector<int> ans(k);
        build(1,1,n);
        for(int i=0;i<n;i++) modify(1,i+1,s[i]);
        for(int i=0;i<k;i++){
            modify(1,queryIndices[i]+1,queryCharacters[i]);
            ans[i]=tr[1].mx;
        }
        return ans;
    }
};
