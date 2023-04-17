/*
将a到b的有向边转化为两条边：一条a到b权值为1的有向边和一条b到a权值为0的有向边
在整棵树上dfs即可
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> e(n);
        for(auto &p:connections){
            int x=p[0],y=p[1];
            e[x].push_back({y,1});
            e[y].push_back({x,0});
        }
        int ans=0;
        function<void(int,int)> dfs=[&](int x,int fa){
            for(auto [y,w]:e[x]){
                if(y==fa) continue;
                ans+=w;
                dfs(y,x);
            }
        };
        dfs(0,-1);
        return ans;
    }
};
