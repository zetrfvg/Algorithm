/*
BFS模拟求解
*/
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                if(u==p){
                    if(sz) return q.front();
                    else return NULL;
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return NULL;
    }
};
