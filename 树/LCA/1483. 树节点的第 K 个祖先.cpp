/*
树上倍增，先求出各个节点其祖先的ST表
回答询问的时候，对k进行二进制拆分，倍增向上找到祖先即可
*/
class TreeAncestor {
public:
    static const int N=5e4+10;
    int fa[N][16];
    TreeAncestor(int n, vector<int>& parent) {
        memset(fa,-1,sizeof fa);
        vector<vector<int>> e(n);
        for(int i=1;i<n;i++){
            e[parent[i]].push_back(i);
        }
        function<void(int)> dfs=[&](int x){
            fa[x][0]=parent[x];
            for(int j=1;j<=15;j++){
                if(fa[x][j-1]!=-1){
                    fa[x][j]=fa[fa[x][j-1]][j-1];
                }
            }
            for(auto y:e[x]) dfs(y);
        };
        dfs(0);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=15;~i;i--){
            if(~node&&(k>>i)&1){
                node=fa[node][i];
            }
        }
        return node;
    }
};
