/*
从小到大枚举因子
暴搜即可
*/
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> res;
        auto dfs=[&](auto self,int x,int y){
            if(x<2){
                if(res.size()>1) ans.push_back(res);
                return;
            }
            for(int i=y;i<=x;i++){
                if(x%i==0){
                    res.push_back(i);
                    self(self,x/i,i);
                    res.pop_back();
                }
            }
        };
        dfs(dfs,n,2);
        return ans;
    }
};
