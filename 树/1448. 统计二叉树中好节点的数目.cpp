/*
简单dfs
*/
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root,int v){
        if(!root) return;
        if(root->val>=v) ans++;
        dfs(root->left,max(v,root->val));
        dfs(root->right,max(v,root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return ans;
    }
};
