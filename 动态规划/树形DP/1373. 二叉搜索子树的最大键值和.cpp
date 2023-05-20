/*
定义状态：
dp[i]={子树最大值，子树最小值，子树和，子树是否为BST}
*/
class Solution {
public:
    static const int inf=1e9;
    int maxSumBST(TreeNode* root) {
        int ans=0;
        function<vector<int>(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root){
                return vector<int>{-inf,inf,0,1};
            }
            auto l=dfs(root->left);
            auto r=dfs(root->right);
            if(l[3]&&r[3]&&root->val>l[0]&&root->val<r[1]){
                ans=max(ans,l[2]+r[2]+root->val);
                return vector<int>{max({l[0],r[0],root->val}),min({l[1],r[1],root->val}),l[2]+r[2]+root->val,1};
            }else{
                return vector<int>{-inf,inf,0,0};
            }
        };
        dfs(root);
        return ans;
    }
};
