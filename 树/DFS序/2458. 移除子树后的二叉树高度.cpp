/*
求出整棵树的dfs序(序列上维护的是各个点的深度)
求删去一个点后的树高，即对该点在dfs序上的区间以外，找最大值，预处理出序列的前后缀后，即可O(1)回答询问
*/
class Solution {
public:
    static const int N=1e5+10;
    int L[N],R[N],dfn;
    int pre[N],suf[N];
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        function<void(TreeNode*,int)> dfs=[&](TreeNode* root,int depth){
            if(!root) return;
            int x=root->val;
            L[x]=++dfn,pre[dfn]=suf[dfn]=depth;
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
            R[x]=dfn;
        };
        dfs(root,0);
        for(int i=1;i<=dfn;i++) pre[i]=max(pre[i],pre[i-1]);
        for(int i=dfn;i;i--) suf[i]=max(suf[i],suf[i+1]);
        vector<int> ans;
        for(auto x:queries){
            ans.push_back(max(pre[L[x]-1],suf[R[x]+1]));
        }
        return ans;
    }
};
