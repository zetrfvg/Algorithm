/*
dfs出包含两个节点的最小子树即可
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return 0;
            int res=(root==p||root==q);
            res+=dfs(root->left);
            res+=dfs(root->right);
            if(res==2&&!ans) ans=root;
            return res;
        };
        dfs(root);
        return ans;
    }
};
