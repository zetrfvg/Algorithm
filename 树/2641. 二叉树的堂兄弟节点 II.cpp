/*
两边DFS
第一遍DFS求每一层的和
第二遍DFS计算，对于每个节点，我们把它左儿子的值传给右儿子，右儿子的值传给左儿子。
则如果计算左儿子的值，用左儿子当前层的总和减去左儿子的值再减去传入的右儿子的值即可；计算右儿子同理
*/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> dep;
        function<void(TreeNode*,int)> dfs1=[&](TreeNode* root,int h){
            if(dep.size()<h) dep.push_back(root->val);
            else dep[h-1]+=root->val;
            if(root->left) dfs1(root->left,h+1);
            if(root->right) dfs1(root->right,h+1);
        };
        dfs1(root,1);
        function<void(TreeNode*,int,int)> dfs2=[&](TreeNode* root,int last,int h){
            root->val=dep[h]-root->val-last;
            int vl=0,vr=0;
            if(root->left) vl+=root->left->val;
            if(root->right) vr+=root->right->val;
            if(root->left) dfs2(root->left,vr,h+1);
            if(root->right) dfs2(root->right,vl,h+1);
        };
        dfs2(root,0,0);
        return root;
    }
};
