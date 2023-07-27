/*
递归定义层数，叶子节点为第一层，模拟dfs即可
*/
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int,vector<int>> p;
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return 0;
            int h=max(dfs(root->left),dfs(root->right))+1;
            p[h].push_back(root->val);
            return h;
        };
        dfs(root);
        vector<vector<int>> ans;
        for(auto &[a,b]:p) ans.push_back(b);
        return ans;
    }
};
