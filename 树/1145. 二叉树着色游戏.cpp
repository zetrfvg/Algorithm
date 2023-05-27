/*
以x为根结点，如果一颗子树大小超过n的一半，则说明y有必胜的策略
*/
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* X;
        function<void(TreeNode*)> dfs1=[&](TreeNode* root){
            if(!root) return;
            if(root->val==x) X=root;
            dfs1(root->left);
            dfs1(root->right);
        };
        dfs1(root);
        bool ok=0;
        function<int(TreeNode*)> dfs2=[&](TreeNode* root){
            if(!root) return 0;
            int l=dfs2(root->left);
            int r=dfs2(root->right);
            if(root==X&&(l*2>n||r*2>n)) ok=1;
            return l+r+1;
        };
        if((n-dfs2(X))*2>n) ok=1;
        return ok;
    }
};
