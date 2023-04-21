/*
树形DP
状态定义：
dp[i][0]：dfs到节点i，选择父边的最大价值
dp[i][1]：dfs到节点i，不选择父边的最大价值
转移方程：
dp[i][0]=Σdp[son][1]，son为i的子节点
dp[i][1]=Σdp[son][1]+dp[j][0]-dp[j][1]，j为子节点中dp[son][0]最大的一个，即选择一条权值最大的子边
*/
class Solution {
public:
    long long maxScore(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<pair<int,long long>>> e(n);
        for(int i=1;i<n-1;i++){
            e[edges[i][0]].push_back({i,edges[i][1]});
        }
        function<vector<long long>(int,int)> dfs=[&](int x,long long v){
            vector<long long> res(2);
            res[0]=v;
            long long t=0;
            for(auto &[y,w]:e[x]){
                auto son=dfs(y,w);
                res[0]+=son[1];
                res[1]=max(res[1]+son[1],t+son[0]);
                t+=son[1];
            }
            return res;
        };
        auto ans=dfs(0,0);
        return max(ans[0],ans[1]);
    }
};
