/*
与二叉搜索树毫无关系，用set来存下树中所有的元素
每个节点的颜色只取决于最后一次的染色，倒序枚举操作
操作[type,l,r]，我们二分找到位于区间[l,r]中的所有元素，对其模拟染色即可，然后从set中删去
每个结点最多被二分找到一次，时间复杂度O(nlogn)
*/
class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        set<int> st;
        function<void(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return;
            st.insert(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        int ans=0;
        for(int i=ops.size()-1;~i;i--){
            int c=ops[i][0],l=ops[i][1],r=ops[i][2];
            while(1){
                auto p=st.lower_bound(l);
                if(p==st.end()||r<*p) break;
                st.erase(p);
                ans+=c;
            }
        }
        return ans;
    }
};
