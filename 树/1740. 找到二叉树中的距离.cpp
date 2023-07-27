/*
一种麻烦的做法
 */
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        vector<vector<int>> e(10010);
        vector<int> vis(10010);
        unordered_map<int,int> mp;
        int idx=0;
        function<void(TreeNode*,int)> dfs=[&](TreeNode* root,int fa){
            if(!root) return;
            mp[root->val]=++idx;
            if(fa!=-1){
                e[fa].push_back(mp[root->val]);
                e[mp[root->val]].push_back(fa);
            }
            dfs(root->left,mp[root->val]);
            dfs(root->right,mp[root->val]);
        };
        dfs(root,-1);
        queue<pair<int,int>> que;
        que.push({0,mp[p]});
        vis[mp[p]]=1;
        while(!que.empty()){
            auto [d,x]=que.front();
            que.pop();
            if(x==mp[q]) return d;
            for(auto y:e[x]){
                if(vis[y]) continue;
                que.push({d+1,y});
                vis[y]=1;
            }
        }
        return -1;
    }
};
