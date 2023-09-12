/*
递归返回子树总和和子树节点个数即可计算出每个子树的平均值
*/
class Solution {
public:
    struct pair {
        int first;
        int second;
        pair operator+(const pair& other) const {
            return pair{first+other.first,second+other.second};
        }
    };
    double maximumAverageSubtree(TreeNode* root) {
        double ans=0;
        function<pair(TreeNode*)> dfs=[&](TreeNode* root)->pair{
            if(!root) return {0,0};
            pair res=dfs(root->left)+dfs(root->right);
            res.first+=root->val,res.second++;
            ans=max(ans,(double)res.first/res.second);
            return res;
        };
        dfs(root);
        return ans;
    }
};
