/*
叶子节点之间按大小顺序形成了一个环，在环中的结点u有如下性质：
u的右指针指向比u大的点，u的左指针指向比u小的点
另一个意思就是，u的右儿子的左指针指向自身，u的左儿子的右指针指向自身
基于这点就可以判断该点是否在环中，即该点是不是叶子节点
*/
class Solution {
public:
    int heightOfTree(TreeNode* root) {
        int dep=-1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                if(p->left&&p->left->right!=p) q.push(p->left);
                if(p->right&&p->right->left!=p) q.push(p->right);
            }
            dep++;
        }
        return dep;
    }
};
