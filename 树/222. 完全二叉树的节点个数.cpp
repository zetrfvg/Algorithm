/*
递归计数即可
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
