/*
视1为根结点，由于值域为[1,26]，维护根结点到树中各个节点的前缀，这里的前缀是路径中边权的个数
回答询问q=[x,y]时，我们找到z=LCA(x,y)，将x和y的前缀相加，再减去z的前缀的两倍，即可得到x到y的简单路径上边权的个数的集合
用边的数量减去该集合中的最大值就是询问的答案
*/
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> e(n+1);
        for(auto &ed:edges){
            e[ed[0]+1].push_back({ed[1]+1,ed[2]});
            e[ed[1]+1].push_back({ed[0]+1,ed[2]});
        }
        int P=log2(n)+1;
        vector<int> dep(n+1);
        vector<vector<int>> fa(P,vector<int>(n+1));
        vector<vector<int>> pre(27,vector<int>(n+1));
        function<void(int,int)> dfs=[&](int x,int father){
            fa[0][x]=father,dep[x]=dep[father]+1;
            for(int i=0;i<=26;i++){
                pre[i][x]+=pre[i][father];
            }
            for(auto [y,w]:e[x]){
                if(y==father) continue;
                pre[w][y]++;
                dfs(y,x);
            }
        };
        dfs(1,0);
        for(int i=1;i<P;i++){
            for(int j=1;j<=n;j++){
                fa[i][j]=fa[i-1][fa[i-1][j]];
            }
        }
        vector<int> ans;
        for(auto &q:queries){
            int x=q[0]+1,y=q[1]+1;
            if(dep[x]<dep[y]) swap(x,y);
            for(int i=P-1;~i;i--){
                if(dep[fa[i][x]]>=dep[y]) x=fa[i][x];
            }
            for(int i=P-1;~i;i--){
                if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
            }
            int sum=0,mx=0,z=x==y?y:fa[0][x];
            x=q[0]+1,y=q[1]+1;
            for(int i=0;i<=26;i++){
                int tot=pre[i][x]+pre[i][y]-2*pre[i][z];
                sum+=tot,mx=max(mx,tot);
            }
            ans.push_back(sum-mx);
        }
        return ans;                       
    }
};
