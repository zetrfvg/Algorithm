/*
暴力DFS＋树形DP
用数组w来统计每个点会产生多少费用
对于每次旅行，暴力DFS，统计每个点经过了多少次，如点x经过了cnt次，则w[x]=cnt*price[x]
然后对于一颗各个点权为w[i]的树，跑一遍树形DP即可 
*/
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> e(n);
        vector<int> w(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        function<bool(int,int,int)> dfs=[&](int x,int fa,int end){
            if(x==end){
                w[x]+=price[x];
                return true;
            }
            for(auto y:e[x]){
                if(y==fa) continue;
                if(dfs(y,x,end)){
                    w[x]+=price[x];
                    return true;
                }
            }
            return false;
        };
        for(auto tr:trips){
            dfs(tr[0],-1,tr[1]);
        }
        function<vector<int>(int,int)> dfs2=[&](int x,int fa){
            vector<int> res{w[x]/2,w[x]};
            for(auto y:e[x]){
                if(y==fa) continue;
                auto son=dfs2(y,x);
                res[0]+=son[1];
                res[1]+=min(son[0],son[1]);
            }
            return res;
        };
        auto ans=dfs2(0,-1);
        return min(ans[0],ans[1]);
    }
};
