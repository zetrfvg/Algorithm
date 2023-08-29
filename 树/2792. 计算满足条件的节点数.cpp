/*
dfs+有序数组合并
*/
class Solution {
public:
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int ans=0;
        function<vector<int>(TreeNode*)> dfs=[&](TreeNode* root){
            vector<int> res(k,1e9);
            if(!root) return res;
            auto l=dfs(root->left);
            auto r=dfs(root->right);
            int u=0,i=0,j=0;
            while(u<k&&i<l.size()&&j<r.size()){
                if(l[i]<r[j]) res[u++]=l[i++];
                else res[u++]=r[j++];
            }
            while(u<k&&i<l.size()){
                res[u++]=l[i++];
            }
            while(u<k&&j<r.size()){
                res[u++]=r[j++];
            }
            if(root->val>res.back()) ans++;
            res.back()=min(res.back(),root->val);
            int p=k-1;
            while(p&&res[p]<res[p-1]) swap(res[p-1],res[p--]);
            return res;
        };
        dfs(root);
        return ans;
    }
};
