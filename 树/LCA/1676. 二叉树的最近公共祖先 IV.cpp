/*
dfs，遇到要查询的节点就+1，找到总和等于要查询的节点个数的第一个节点即可
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        int sum=nodes.size();
        TreeNode* ans=NULL;
        set<TreeNode*> st(nodes.begin(),nodes.end());
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return 0;
            int res=st.count(root);
            res+=dfs(root->left);
            res+=dfs(root->right);
            if(res==sum&&!ans) ans=root;
            return res;
        };
        dfs(root);
        return ans;
    }
};
