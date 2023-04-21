/*
两次DFS做法
*/
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> e(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        vector<int> dep(n);
        int ans=0,rt=0;
        function<void(int,int,int)> dfs=[&](int x,int fa,int depth){
            dep[x]=depth;
            if(dep[x]>ans){
                ans=dep[x];
                rt=x;
            }
            for(auto y:e[x]){
                if(y==fa) continue;
                dfs(y,x,depth+1);
            }
        };
        dfs(rt,-1,0);
        dfs(rt,-1,0);
        return ans;
    }
};
/*
树形DP
*/
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> e(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        int ans=0;
        function<int(int,int)> dfs=[&](int x,int fa){
            int mx=0;
            for(auto y:e[x]){
                if(y==fa) continue;
                int len=dfs(y,x);
                ans=max(ans,len+mx);
                mx=max(mx,len);
            }
            return mx+1;
        };
        dfs(0,-1);
        return ans;
    }
};
