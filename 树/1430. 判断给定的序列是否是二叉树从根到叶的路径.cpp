/*
暴力，用set来存下所有路径的序列，最后判断集合中是否有arr即可
*/
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        set<vector<int>> st;
        vector<int> p;
        function<void(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return;
            p.push_back(root->val);
            if(!root->left&&!root->right) st.insert(p);
            dfs(root->left);
            dfs(root->right);
            p.pop_back();
        };
        dfs(root);
        return st.count(arr);
    }
};
