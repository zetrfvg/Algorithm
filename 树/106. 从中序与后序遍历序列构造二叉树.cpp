/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<TreeNode*,int> L,R;
        unordered_map<int,int>pos;
        for(int i=0;i<n;i++){
            pos[inorder[i]]=i;
        }
        auto build=[&](auto self,int lm,int rm,int ls,int rs)->TreeNode*{
            int val=postorder[rs];
            TreeNode *rt=new TreeNode(val);
            int u=pos[val];
            if(lm<u){
                rt->left=self(self,lm,u-1,ls,ls+u-1-lm);
            }
            if(rm>u){
                rt->right=self(self,u+1,rm,ls+u-lm,rs-1);
            }
            return rt;
        };
        return build(build,0,n-1,0,n-1);
    }
};
