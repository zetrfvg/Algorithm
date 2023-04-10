/*
状态定义：
用状态dp[i][4]来描述当前节点i状态，其中：
dp[i][0]：以节点i为根的子树是否是合法的BST
dp[i][1]：以节点i为根的子树大小
dp[i][2]：以节点i为根的子树中的最大值元素
dp[i][3]：以节点i为根的子树中的最小值元素
状态转移：
dp[i][0]=dp[left][0]&&r[0]&&root->val>dp[left][2]&&root->val<dp[right][3];
dp[i][1]+=dp[left][1]+dp[right][1]+1;
dp[i][2]=max({root->val,dp[left][2],dp[right][2]});
dp[i][3]=min({root->val,dp[left][3],dp[right][3]});
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ans=0;
        function<vector<int>(TreeNode*)> dfs=[&](TreeNode* root){
            vector<int> res={1,0,(int)-1e9,(int)1e9};
            if(!root){
                return vector{1,0,(int)-1e9,(int)1e9};
            }
            auto l=dfs(root->left);
            auto r=dfs(root->right);
            res[0]=l[0]&&r[0]&&root->val>l[2]&&root->val<r[3];
            res[1]+=l[1]+r[1]+1;
            res[2]=max({root->val,l[2],r[2]});
            res[3]=min({root->val,l[3],r[3]});
            if(res[0]) ans=max(ans,res[1]);
            return res;
        };
        dfs(root);
        return ans;
    }
};
