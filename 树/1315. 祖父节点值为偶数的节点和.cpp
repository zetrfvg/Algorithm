/*
dfs三个参数，祖父节点的值，父亲节点的值，当前节点
*/
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        function<void(int,int,TreeNode*)> dfs=[&](int gr,int fa,TreeNode* root){
            if(!root) return;
            if(gr%2==0) ans+=root->val;
            dfs(fa,root->val,root->left);
            dfs(fa,root->val,root->right);
        };
        dfs(1,1,root);
        return ans;
    }
};
