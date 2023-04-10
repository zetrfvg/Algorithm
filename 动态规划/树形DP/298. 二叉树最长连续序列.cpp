/*
状态定义：
dp[i]：以节点i为起点能够向下走的最长连续序列的长度
转移方程：
如果root->val+1==root->left->val，dp[i]=max(dp[i]，dp[left]+1)
如果root->val+1==root->right->val，dp[i]=max(dp[i]，dp[right]+1)
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ans=0;
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            int res=1;
            if(root->left){
                int l=dfs(root->left);
                if(root->val+1==root->left->val&&l+1>res){
                    res=l+1;
                }
            }
            if(root->right){
                int r=dfs(root->right);
                if(root->val+1==root->right->val&&r+1>res){
                    res=r+1;
                }
            }
            ans=max(ans,res);
            return res;
        };
        dfs(root);
        return ans;
    }
};
