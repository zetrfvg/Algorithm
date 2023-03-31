/*
首先遍历整棵树，求出每个点的父节点及其深度
让p与q中深度更大的点向上一步一步找父亲，直到二者位于同一层
如果此时p==q，那么此时p是它们的LCA
否则，二者同时向上找父亲，直到p==q为止
*/
class Solution {
public:
    map<TreeNode*,TreeNode*> pa;
    map<TreeNode*,int> h;
    void dfs(TreeNode* root,TreeNode* fa,int cur){
        if(!root) return;
        pa[root]=fa;
        h[root]=cur;
        dfs(root->left,root,cur+1);
        dfs(root->right,root,cur+1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,NULL,0);
        while(p!=q){
            if(h[p]<h[q]) swap(p,q);
            p=pa[p];
        }
        return p;
    }
};
