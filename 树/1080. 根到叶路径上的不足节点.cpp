/*
*/
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<bool(TreeNode*,long long)> dfs=[&](TreeNode* root,long long sum)->bool{
            if(!root) return false;//空结点
            sum+=root->val;
            if(!root->left&&!root->right){
                return sum>=limit;//叶子节点，返回是否合法
            }
            bool l=dfs(root->left,sum),r=dfs(root->right,sum);
            if(!l) root->left=NULL;//左子树不存在合法路径
            if(!r) root->right=NULL;//右子树不存在合法路径
            return l|r;//返回当前子树是否合法
        };
        return dfs(root,0)?root:NULL;
    }
};
