/*
简单dfs模拟即可
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        function<TreeNode*(TreeNode*)> dfs=[&](TreeNode* root)->TreeNode*{
            if(!root) return NULL;
            root->left=dfs(root->left);
            root->right=dfs(root->right);
            if(st.count(root->val)){
                if(root->left) ans.push_back(root->left);
                if(root->right) ans.push_back(root->right);
                return NULL;
            }else{
                return root;
            }
        };
        dfs(root);
        if(!st.count(root->val)) ans.push_back(root);
        return ans;
    }
};
