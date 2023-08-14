/*
简单递归模拟题
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        auto res=new TreeNode(root1->val+root2->val);
        res->left=mergeTrees(root1->left,root2->left);
        res->right=mergeTrees(root1->right,root2->right);
        return res;
    }
};
