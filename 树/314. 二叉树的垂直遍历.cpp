/*
哈希表记录维护同一垂序的结点，节点之间的先后顺序由BFS的过程来保证
*/
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>> p;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto [cur,id]=q.front();
            q.pop();
            p[id].push_back(cur->val);
            if(cur->left) q.push({cur->left,id-1});
            if(cur->right) q.push({cur->right,id+1});
        }
        vector<vector<int>> ans;
        for(auto &[a,b]:p) ans.push_back(b);
        return ans;
    }
};
