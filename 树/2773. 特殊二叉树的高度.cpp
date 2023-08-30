/*
叶子节点之间按大小顺序形成了一个环，在环中的结点u有如下性质：
u的右指针指向比u大的点，u的左指针指向比u小的点
另一个意思就是，u的右儿子的左指针指向自身，u的左儿子的右指针指向自身
基于这点就可以判断该点是否在环中，即该点是不是叶子节点
*/
class Solution {
public:
    int heightOfTree(TreeNode* root) {
        int ans=0;
        function<void(TreeNode*,int)> dfs=[&](TreeNode* root,int dep){
            if(!root) return;
            if(root->left&&root->left->right==root){
                ans=max(ans,dep);
                return;
            }
            if(root->right&&root->right->left==root){
                ans=max(ans,dep);
                return;
            }
            dfs(root->left,dep+1);
            dfs(root->right,dep+1);
        };
        dfs(root,0);
        return ans;
    }
};
