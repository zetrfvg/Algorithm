/*
自底向上判断叶子节点是否为target即可，合法则返回空，删除该节点
*/
class Solution {
public:
    TreeNode* dfs(TreeNode* root,int target){
        if(!root) return NULL;
        root->left=dfs(root->left,target);
        root->right=dfs(root->right,target);
        if(!root->left&&!root->right&&root->val==target) return NULL;
        else return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
};
