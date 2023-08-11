/*
简单dfs应用题
*/
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int mx=0,cnt=0;
        TreeNode* ans=NULL;
        function<void(TreeNode*,int)> dfs1=[&](TreeNode* root,int dep){
            if(!root) return;
            if(dep>mx) mx=dep,cnt=1;
            else if(dep==mx) cnt++;
            dfs1(root->left,dep+1);
            dfs1(root->right,dep+1);
        };
        function<int(TreeNode*,int)> dfs2=[&](TreeNode* root,int dep){
            if(!root) return 0;
            int res=dep==mx;
            res+=dfs2(root->left,dep+1);
            res+=dfs2(root->right,dep+1);
            if(res==cnt&&!ans) ans=root;
            return res;
        };
        dfs1(root,0);
        dfs2(root,0);
        return ans;
    }
};
