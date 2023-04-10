/*
状态定义：
dp[i][2]表示以第i个节点为根的子树的状态，其中:
dp[i][0]：以第i个节点为根的子树的节点个数
dp[i][1]：以第i个节点为根的子树的权值之和
转移方程：
dp[i][0]=1+Σdp[j][0]
dp[i][1]=value[i]+Σdp[j][1]
其中，j为节点i的子节点
当dp[i][1]==0时，要删去这个子树，令dp[i][0]=0
*/
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> e(nodes);
        for(int i=1;i<nodes;i++) e[parent[i]].push_back(i);
        function<vector<int>(int)> dfs=[&](int x){
            vector<int> res{1,value[x]};
            for(int y:e[x]){
                auto p=dfs(y);
                res[0]+=p[0],res[1]+=p[1];
            }
            if(!res[1]) res[0]=0;
            return res;
        };
        return dfs(0)[0];
    }
};
