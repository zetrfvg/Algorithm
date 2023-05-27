/*
首先求出树深
第二次dfs枚举每个节点能走到的最深的节点的数量，取最大即为答案
*/
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx=1,dep=0;
        TreeNode* ans=NULL;
        function<void(TreeNode*,int)> getdep=[&](TreeNode* root,int cur){
            if(!root) return;
            if(cur>dep) ans=root;
            dep=max(dep,cur);
            getdep(root->left,cur+1);
            getdep(root->right,cur+1);
        };
        getdep(root,1);
        function<int(TreeNode*,int)> dfs=[&](TreeNode* root,int cur){
            if(cur==dep) return 1;
            int res=0;
            if(root->left) res+=dfs(root->left,cur+1);
            if(root->right) res+=dfs(root->right,cur+1);
            if(res>mx){
                mx=res;
                ans=root;
            }
            return res;
        };
        dfs(root,1);
        return ans;
    }
};
