/*
第一次dfs求出以0节点为根需要翻转的边的数量cnt
第二次dfs，遇见正向边，说明递归该边指向的子节点时，该子节点作为根需要翻转该边，此时cnt+1；否则无需翻转，cnt-1
*/
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> e(n);
        for(auto ed:edges){
            e[ed[0]].push_back({ed[1],1});
            e[ed[1]].push_back({ed[0],0});
        }
        int cnt=0;
        function<void(int,int)> dfs1=[&](int x,int fa){
            for(auto [y,w]:e[x]){
                if(y==fa) continue;
                if(!w) cnt+=w;
                dfs1(y,x);
            }
        };
        dfs1(0,-1);
        vector<int> ans(n);
        function<void(int,int,int)> dfs2=[&](int x,int fa,int c){
            ans[x]=c;
            for(auto [y,w]:e[x]){
                if(y==fa) continue;
                if(!w) dfs2(y,x,c-1);
                else dfs2(y,x,c+1);
            }  
        };
        dfs2(0,-1,cnt);
        return ans;
    }
};
