/*
对于一组查询[x,y,z]
他们两两之间的LCA分别为xy,yz,xz
其中必有两者的LCA的是相同的，则这组询问的答案为第三个不同的LCA
如：如果xy==yz，那么该组询问的点为xz
*/
class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> fa(n,vector<int>(11));
        vector<vector<int>> e(n);
        vector<int> dep(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        function<void(int,int)> dfs=[&](int x,int father){
            dep[x]=dep[father]+1;
            fa[x][0]=father;
            for(int i=1;i<11;i++){
                fa[x][i]=fa[fa[x][i-1]][i-1];
            }
            for(auto &y:e[x]){
                if(y==father) continue;
                dfs(y,x);
            }
        };
        dfs(0,0);
        function<int(int,int)> lca=[&](int x,int y){
            if(dep[y]>dep[x]) swap(x,y);
            for(int i=10;~i;i--){
                if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
            }
            if(x==y) return x;
            for(int i=10;~i;i--){
                if(fa[x][i]!=fa[y][i]){
                    x=fa[x][i],y=fa[y][i];
                }
            }
            return fa[x][0];
        };
        int m=query.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int x=query[i][0],y=query[i][1],z=query[i][2];
            int xy=lca(x,y),xz=lca(x,z),yz=lca(y,z);
            if(xy==xz){
                ans[i]=yz;
            }else if(xy==yz){
                ans[i]=xz;
            }else{
                ans[i]=xy;
            }
        }
        return ans;
    }
};
