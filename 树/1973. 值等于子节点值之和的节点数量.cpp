/*
简单dfs模拟即可
*/
class Solution {
public:
    using ll=long long;
    int equalToDescendants(TreeNode* root) {
        int ans=0;
        function<ll(TreeNode*)> dfs=[&](TreeNode* cur)->ll{
            if(!cur) return 0;
            ll res=dfs(cur->left)+dfs(cur->right);
            if(res==cur->val) ans++;
            return res+=cur->val;;
        };
        dfs(root);
        return ans;
    }
};
