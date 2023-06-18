/*
BFS，把每层的最后一个节点加入答案
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                auto p=q.front();
                q.pop();
                if(i==sz) ans.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return ans;
    }
};
