/*
第一次dfs处理出以1为根结点时有多少猜测是正确的
第二次dfs枚举每个点作为根有多少猜测是正确的
*/
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n=edges.size()+1;
        vector<unordered_set<int>> g(n);
        vector<vector<int>> e(n);
        for(auto p:guesses){
            g[p[0]].insert(p[1]);
        }
        for(auto p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        int ans=0,cnt=0;
        function<void(int,int)> dfs1=[&](int x,int fa){
            for(auto y:e[x]){
                if(y==fa) continue;
                if(g[x].count(y)) cnt++;
                dfs1(y,x);
            }
        };
        function<void(int,int,int)> dfs2=[&](int x,int fa,int cnt){
            if(g[x].count(fa)) cnt++;//多一个正确的猜测
            if(cnt>=k) ans++;
            for(auto y:e[x]){
                if(y==fa) continue;
                if(g[x].count(y)) dfs2(y,x,cnt-1);//少一个正确的猜测
                else dfs2(y,x,cnt);
            }
        };
        dfs1(0,-1);
        dfs2(0,-1,cnt);
        return ans;
    }
};
