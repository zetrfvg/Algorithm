/*
暴搜加剪枝

去重剪枝：不妨先对数组排序，如果元素x不选，那么后面与x相等的元素也不能选，以此达到去重的效果
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        int pre=0;
        function<void(int)> dfs=[&](int x){
            if(pre==target) ans.push_back(cur);
            if(x==n||pre>=target) return;
            pre+=candidates[x];
            cur.push_back(candidates[x]);
            dfs(x+1);
            pre-=candidates[x];
            cur.pop_back();
            int y=x+1;
            while(y<n&&candidates[y]==candidates[x]) y++;
            dfs(y);
        };
        dfs(0);
        return ans;
    }
};
