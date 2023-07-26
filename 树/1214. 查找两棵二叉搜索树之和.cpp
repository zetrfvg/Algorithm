/*
哈希表做法
*/
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> st;
        function<void(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return;
            st.insert(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root1);
        queue<TreeNode*> q;
        q.push(root2);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(st.count(target-p->val)) return true;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return false;
    }
};
