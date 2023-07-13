/*
简单递归
*/
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root||!root->left) return root;
        auto l=root->left,r=root->right;
        root->left=root->right=NULL;
        auto res=upsideDownBinaryTree(l);
        l->left=r,l->right=root;
        return res;
    }
};
