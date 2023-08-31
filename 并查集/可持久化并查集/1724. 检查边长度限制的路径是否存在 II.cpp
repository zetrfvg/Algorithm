/*
可持久化并查集模板题
*/
class DistanceLimitedPathsExist {
public:
    static const int N=1e4+10;
    struct node{
        int l,r;
        int ls,rs;
        int fa,dep;
    }tr[N*20];
    int idx=0,id=0,rt[N];
    vector<int> w;

    int build(int l,int r){
        int root=++idx;
        tr[root]={l,r,0,0,l,1};
        if(l==r) return root;
        int m=(l+r)>>1;
        tr[root].ls=build(l,m);
        tr[root].rs=build(m+1,r);
        return root;
    }

    int modify_fa(int son,int fa,int root){
        int cur=++idx;
        tr[cur]=tr[root];
        if(tr[cur].l==son&&tr[cur].r==son){
            tr[cur].fa=fa;
            return cur;
        }
        int m=(tr[cur].l+tr[cur].r)>>1;
        if(son<=m) tr[cur].ls=modify_fa(son,fa,tr[root].ls);
        else tr[cur].rs=modify_fa(son,fa,tr[root].rs);
        return cur;
    }

    int modify_dep(int fa,int root){
        int cur=++idx;
        tr[cur]=tr[root];
        if(tr[cur].l==fa&&tr[cur].r==fa){
            tr[cur].dep++;
            return cur;
        }
        int m=(tr[cur].l+tr[cur].r)>>1;
        if(fa<=m) tr[cur].ls=modify_dep(fa,tr[root].ls);
        else tr[cur].rs=modify_dep(fa,tr[root].rs);
        return cur;
    }

    int query_find(int x,int u){
        if(tr[u].l==tr[u].r){
            return u;
        }
        int m=(tr[u].l+tr[u].r)>>1;
        if(x<=m) return query_find(x,tr[u].ls);
        else return query_find(x,tr[u].rs);
    }

    int query_fa(int x,int u){
        int v=query_find(x,u);
        if(tr[v].fa==x) return v;
        else return query_fa(tr[v].fa,u);
    }

    int get(int limit){
        if(limit<=w[0]) return 0;
        else return lower_bound(w.begin(),w.end(),limit)-w.begin();
    }

    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        sort(edgeList.begin(),edgeList.end(),[](const auto &a,const auto &b){
            return a[2]<b[2];
        });//按路径权值升序合并
        for(int i=0;i<edgeList.size();i++) w.push_back(edgeList[i][2]);
        w.erase(unique(w.begin(),w.end()),w.end());
        rt[id++]=build(1,n);//id记录并查集的版本号
        for(int i=0;i<edgeList.size();){
            int j=i;
            rt[id]=rt[id-1];
            while(j<edgeList.size()&&edgeList[i][2]==edgeList[j][2]){//长度相同的路径记在同一版本中
                int u=query_fa(edgeList[j][0]+1,rt[id]),v=query_fa(edgeList[j][1]+1,rt[id]);//找到两个节点的祖先
                if(tr[u].fa==tr[v].fa){//二者在同一集合中，跳过
                    j++;
                    continue;
                }
                if(tr[u].dep<tr[v].dep) swap(u,v);//按秩合并，小秩的集合合并到大秩的集合中去
                rt[id]=modify_fa(tr[v].fa,tr[u].fa,rt[id]);//合并
                if(tr[u].dep==tr[v].dep) rt[id]=modify_dep(tr[u].fa,rt[id]);//两个集合的秩相同，新集合的秩要加1
                j++;
            }
            i=j,id++;//更新版本号
        }
    }
    
    bool query(int p, int q, int limit) {
        int v=get(limit);//找到满足条件的最大版本
        p=query_fa(p+1,rt[v]),q=query_fa(q+1,rt[v]);//查询祖先
        return tr[p].fa==tr[q].fa;//判断是否在同一集合中
    }
};
