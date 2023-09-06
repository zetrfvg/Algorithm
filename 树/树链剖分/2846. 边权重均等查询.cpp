/*
树剖求LCA+前缀和
*/
class Solution {
public:
    static const int N=1e4+10;
    int dep[N],sz[N],son[N];
    int fa[N],top[N];
    vector<pair<int,int>> e[N];
    int pre[N][27];

    void dfs1(int x,int father,int depth){
        fa[x]=father,dep[x]=depth,sz[x]=1;
        for(auto [y,w]:e[x]){
            if(y==father) continue;
            for(int j=0;j<=26;j++) pre[y][j]+=pre[x][j];
            pre[y][w]++;
            dfs1(y,x,depth+1);
            sz[x]+=sz[y];
            if(sz[son[x]]<sz[y]) son[x]=y;
        }
    }

    void dfs2(int x,int t){
        top[x]=t;
        if(!son[x]) return;
        dfs2(son[x],t);
        for(auto [y,w]:e[x]){
            if(y==fa[x]||y==son[x]) continue;
            dfs2(y,y);
        }
    }

    int lca(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y]) swap(x,y);
        return x;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(auto &ed:edges){
            e[ed[0]+1].push_back({ed[1]+1,ed[2]});
            e[ed[1]+1].push_back({ed[0]+1,ed[2]});
        }
        dfs1(1,0,1);
        dfs2(1,1);
        vector<int> ans;
        for(auto q:queries){
            int x=q[0]+1,y=q[1]+1,z=lca(x,y);
            int sum=0,mx=0;
            for(int i=0;i<=26;i++){
                int t=pre[x][i]+pre[y][i]-2*pre[z][i];
                sum+=t,mx=max(mx,t);
            }
            ans.push_back(sum-mx);
        }
        return ans;                       
    }
};
