/*
对于一颗子树，它共有coins个硬币，nodes个结点
如果coins-nodes>=0，则说明这颗子树需要移coins-nodes个硬币出去
否则，说明这颗子树需要移nodes-coins个硬币进来
对于一棵子树，其移动的贡献为abs(coins-nodes)，累加所有子树的贡献即为答案
*/
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans=0;
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return 0;
            int res=dfs(root->left)+dfs(root->right)+root->val-1;
            ans+=abs(res);
            return res;
        };
        dfs(root);
        return ans;
    }
};
