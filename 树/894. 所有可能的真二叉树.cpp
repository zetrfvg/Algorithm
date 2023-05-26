/*
递归构造
对于一颗大小为n+1的树
我们枚举它的左子树大小分别为(0,2···n)的各种方案，同时枚举它的右子树大小分别为(n,n-2,···0)的各种方案
*/
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        n--;
        if(n%2) return {};
        if(!n){
            return {new TreeNode(0)};
        }
        vector<TreeNode*> ans;
        for(int i=1;i<=n;i+=2){
            auto l=allPossibleFBT(i);
            auto r=allPossibleFBT(n-i);
            for(auto ll:l){
                for(auto rr:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=ll;
                    root->right=rr;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
