/*
树形DP
*/
class Solution {
public:
    int diameter(Node* root) {
        int ans=0;
        function<int(Node*)> dfs=[&](Node* root){
            int mx=0;
            for(auto ch:root->children){
                int len=dfs(ch);
                ans=max(ans,len+mx);
                mx=max(mx,len);
            }
            return mx+1;
        };
        dfs(root);
        return ans;
    }
};
