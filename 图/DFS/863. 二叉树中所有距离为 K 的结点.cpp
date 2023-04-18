/*
建图+DFS
找距离为k的点
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> e(510);
        function<void(TreeNode*,int)> dfs1=[&](TreeNode* root,int fa){
            int x=root->val;
            if(fa!=-1){
                e[x].push_back(fa);
                e[fa].push_back(x);
            }
            if(root->left) dfs1(root->left,x);
            if(root->right) dfs1(root->right,x);
        };
        dfs1(root,-1);
        vector<int> ans;
        function<void(int,int,int)> dfs2=[&](int x,int fa,int d){
            if(d==k){
                ans.push_back(x);
                return;
            }
            for(auto &y:e[x]){
                if(y!=fa){
                    dfs2(y,x,d+1);
                }
            }
        };
        dfs2(target->val,-1,0);
        return ans;
    }
};
