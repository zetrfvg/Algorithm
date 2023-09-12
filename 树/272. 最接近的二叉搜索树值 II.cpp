/*
dfs枚举所有元素
取k个最近的元素，排序，优先队列均可
*/
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        function<void(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return;
            ans.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        sort(ans.begin(),ans.end(),[&](const auto &x,const auto &y){
            return fabs((double)x-target)<fabs((double)y-target);
        });
        ans.erase(ans.begin()+k,ans.end());
        return ans;
    }
};
