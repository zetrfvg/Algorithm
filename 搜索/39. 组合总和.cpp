/*
暴搜
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n=candidates.size();
        auto dfs=[&](auto self,int x){
            if(!target){
                ans.push_back(res);
                return;
            }
            if(x==n) return;
            self(self,x+1);
            if(target-candidates[x]>=0){
                res.push_back(candidates[x]);
                target-=candidates[x];
                self(self,x);
                res.pop_back();
                target+=candidates[x];
            }
        };
        dfs(dfs,0);
        return ans;
    }
};
