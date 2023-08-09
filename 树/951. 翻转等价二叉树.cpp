/*
dfs验证，如果root1中的某个节点x，和root2中对应节点y的左右儿子不同，则交换x的两个儿子，继续向下搜索验证
*/
class Solution {
public:
    bool equal(TreeNode* x,TreeNode* y){
        if(!x&&!y) return true;
        if(!x||!y) return false;
        return x->val==y->val;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans=1;
        function<void(TreeNode*,TreeNode*)> dfs=[&](TreeNode* x,TreeNode* y){
            if(!x) return;
            if(!equal(x->left,y->left)||!equal(x->right,y->right)){
                swap(x->left,x->right);
                if(!equal(x->left,y->left)||!equal(x->right,y->right)){
                    ans=0;
                    return;
                }
            }
            dfs(x->left,y->left);
            dfs(x->right,y->right);
        };
        if(!equal(root1,root2)) return false;
        dfs(root1,root2);
        return ans;
    }
};
