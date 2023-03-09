class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> dep(n);
        for(auto p:edges){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        //第一遍dfs求所有子树的高度
        auto dfs1=[&](auto self,int x,int fa)->void{
            if(g[x].size()==1&&g[x][0]==fa){
                dep[x]=1;
                return;
            }
            for(auto y:g[x]){
                if(y!=fa){
                    self(self,y,x);
                    dep[x]=max(dep[x],dep[y]+1);
                }
            }
        };
        dfs1(dfs1,0,-1);
        vector<int> ans;
        int h=1e9;
        //换根DP，当结点x作为根结点，维护子树的最大高度和次大高度
        //转移的时候，向最高的子树把次大高度转移下去，向其他子树转移最大高度
        auto dfs2=[&](auto self,int x,int fa,int lst)->void{
            int a=lst,b=0;
            int u=-1,v=-1;
            for(auto y:g[x]){
                if(y==fa) continue;
                if(dep[y]>a){
                    b=a,v=u;
                    a=dep[y],u=y;
                }else if(dep[y]>b){
                    b=dep[y],v=y;
                }
            }
            if(a==h) ans.push_back(x);
            else if(a<h){
                h=a;
                ans.resize(0);
                ans.push_back(x);
            }
            for(auto y:g[x]){
                if(y==fa) continue;
                if(y==u) self(self,y,x,b+1);
                else self(self,y,x,a+1);
            }
        };
        dfs2(dfs2,0,-1,0);
        return ans;
    }
};
