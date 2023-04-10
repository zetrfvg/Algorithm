/*
状态定义：
对于每个节点，维护两种状态：
一种是从当前节点能够向下走最长的连续递增序列的长度
一种是从当前节点能够向下走最长的连续递减序列的长度
记dp[i][2]分别为节点i的两种状态
转移方程：
如果root->val-1==root->left->val，dp[i][0]=max(dp[i][0]，dp[left][0]+1)
如果root->val+1==root->left->val，dp[i][1]=max(dp[i][1]，dp[left][1]+1)
如果root->val-1==root->right->val，dp[i][0]=max(dp[i][0]，dp[right][0]+1)
如果root->val+1==root->right->val，dp[i][1]=max(dp[i][1]，dp[right][1]+1)
在转移的同时，维护以第i个节点为根，最长连续序列的长度
记res[0]为路径：左子树--根--右子树的递增的最长连续序列的长度
记res[1]为路径：左子树--根--右子树的递减的最长连续序列的长度
初始res[0]=res[1]=1
如果root->val-1==root->left->val，res[0]+=dp[left][0]
如果root->val+1==root->right->val，res[0]+=dp[right][1]
如果root->val+1==root->left->val，res[1]+=dp[left][1]
如果root->val-1==root->right->val，res[1]+=dp[right][0]
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ans=0;
        function<pair<int,int>(TreeNode*)> dfs=[&](TreeNode* root){
            pair<int,int> res={1,1},mx={1,1};
            if(root->left){
                auto l=dfs(root->left);
                if(root->val-1==root->left->val){
                    res.first+=l.first;
                    mx.first=max(mx.first,l.first+1);
                }else if(root->val+1==root->left->val){
                    res.second+=l.second;
                    mx.second=max(mx.second,l.second+1);
                }
            }
            if(root->right){
                auto r=dfs(root->right);
                if(root->val+1==root->right->val){
                    res.first+=r.second;
                    mx.second=max(mx.second,r.second+1);
                }else if(root->val-1==root->right->val){
                    res.second+=r.first;
                    mx.first=max(mx.first,r.first+1);
                }
            }
            ans=max({ans,res.first,res.second});
            return mx;
        };
        dfs(root);
        return ans;
    }
};
