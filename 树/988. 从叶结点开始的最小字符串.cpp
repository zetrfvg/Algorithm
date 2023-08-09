/*
枚举出所有合法串，找到最小的一个即可
*/
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        function<vector<string>(TreeNode*)> dfs=[&](TreeNode* root){
            vector<string> res;
            if(!root->left&&!root->right){
                res.push_back(string(1,'a'+root->val));
                return res;
            }
            if(root->left){
                auto l=dfs(root->left);
                for(auto s:l) res.push_back(s+='a'+root->val);
            }
            if(root->right){
                auto r=dfs(root->right);
                for(auto s:r) res.push_back(s+='a'+root->val);
            }
            return res;
        };
        auto ans=dfs(root);
        return *min_element(ans.begin(),ans.end());
    }
};
