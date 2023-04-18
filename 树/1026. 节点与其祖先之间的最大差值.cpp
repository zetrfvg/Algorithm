/*
简单DFS
*/
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        function<void(TreeNode*,int,int)> dfs=[&](TreeNode* root,int mx,int mn){
            if(!root) return;
            ans=max({ans,abs(root->val-mx),abs(root->val-mn)});
            dfs(root->left,max(mx,root->val),min(mn,root->val));
            dfs(root->right,max(mx,root->val),min(mn,root->val));
        };
        dfs(root,root->val,root->val);
        return ans;
    }
};
