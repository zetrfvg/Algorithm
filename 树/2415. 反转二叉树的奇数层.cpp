/*
用哈希表存储下每个奇数层的元素
对于一个奇数层的结点，用当前层序列中的对称位置的元素来更新它的值即可
*/
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        map<TreeNode*,int> id;
        map<int,vector<int>> h;
        function<void(TreeNode*,int)> dfs1=[&](TreeNode* root,int dep){
            if(!root) return;
            if(dep&1){
                id[root]=h[dep].size();
                h[dep].push_back(root->val);
            }
            dfs1(root->left,dep+1);
            dfs1(root->right,dep+1);
        };
        function<void(TreeNode*,int)> dfs2=[&](TreeNode* root,int dep){
            if(!root) return;
            if(dep&1){
                root->val=h[dep][h[dep].size()-id[root]-1];
            }
            dfs2(root->left,dep+1);
            dfs2(root->right,dep+1);
        };
        dfs1(root,0);
        dfs2(root,0);
        return root;
    }
};
