/*
每个结点u维护一个pair<int,int>
第一维表示使u评价为0的最少操作数，第二维表示使u评价为1的最少操作数
*/
class Solution {
public:
    using PII=pair<int,int>;
    int minimumFlips(TreeNode* root, bool result) {
        function<PII(TreeNode*)> dfs=[&](TreeNode* root){
            PII res;
            if(root->val==0){
                res.second=1;
            }else if(root->val==1){
                res.first=1;
            }else if(root->val==2){
                auto l=dfs(root->left);
                auto r=dfs(root->right);
                res.first=l.first+r.first;
                res.second=min({l.first+r.second,l.second+r.first,l.second+r.second});
            }else if(root->val==3){
                auto l=dfs(root->left);
                auto r=dfs(root->right);
                res.first=min({l.first+r.first,l.second+r.first,l.first+r.second});
                res.second=l.second+r.second;
            }else if(root->val==4){
                auto l=dfs(root->left);
                auto r=dfs(root->right);
                res.first=min(l.first+r.first,l.second+r.second);
                res.second=min(l.first+r.second,l.second+r.first);
            }else{
                res=root->left?dfs(root->left):dfs(root->right);
                swap(res.first,res.second);
            }
            return res;
        };
        auto ans=dfs(root);
        return result?ans.second:ans.first;
    }
};
