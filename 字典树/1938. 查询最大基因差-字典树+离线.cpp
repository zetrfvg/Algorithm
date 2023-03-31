/*
对整个树进行dfs
当前递归到点x，先将x加入字典树，如果有对x点的查询，则在字典树上进行查询最大异或值
然后对子节点进行递归
递归结束返回之前，需要把x从字典树中进行删除

因为不再是依次回答询问，而是根据dfs到哪个点来回答对应询问，因此需要将所有询问离线下来
此外需要一个设计一个支持删除操作的字典树
*/
class Solution {
public:
    static const int N=1e5+5;
    int tr[31*N][2],cnt[31*N],idx=0;
    void insert(int u,int k){
        int p=0;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(!tr[p][j]) tr[p][j]=++idx;
            p=tr[p][j];
            cnt[p]+=k;
        }
    }
    int query(int u){
        int p=0,res=0;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(cnt[tr[p][!j]]){
                p=tr[p][!j];
                res|=(1<<i);
            }else p=tr[p][j];
        }
        return res;
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        int n=parents.size(),root;
        vector<vector<int>> e(n);
        for(int i=0;i<n;i++){
            int p=parents[i];
            if(p==-1) root=i;
            else e[p].push_back(i);
        }
        int m=queries.size();
        vector<int> ans(m);
        vector<vector<pair<int,int>>> q(n);
        for(int i=0;i<m;i++){
            q[queries[i][0]].push_back({queries[i][1],i});
        }
        auto dfs=[&](auto self,int x)->void{
            insert(x,1);
            for(auto [v,i]:q[x]){
                ans[i]=query(v);
            }
            for(auto y:e[x]){
                self(self,y);
            }
            insert(x,-1);
        };
        dfs(dfs,root);
        return ans;
    }
};
