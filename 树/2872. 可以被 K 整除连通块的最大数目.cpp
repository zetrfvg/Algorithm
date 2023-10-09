/*
递归求和，遇到k的倍数则返回0，连通块加1，没遇到则返回当前节点和
*/
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> e(n);
        for(auto p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        int ans=0;
        function<long long(int,int)> dfs=[&](int x,int fa){
            long long res=values[x];
            for(auto y:e[x]){
                if(y==fa) continue;
                res+=dfs(y,x);
            }
            if(res%k==0) ans++,res=0;
            return res;
        };
        dfs(0,-1);
        return ans;
    }
};
