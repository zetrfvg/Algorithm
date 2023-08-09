/*
枚举所有合法答案
*/
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        function<void(int,int,int)> dfs=[&](int pos,int lst,int cur){
            if(pos==n){
                ans.push_back(cur);
                return;
            }
            for(int i=pos?0:1;i<10;i++){
                if(!pos||abs(i-lst)==k){
                    dfs(pos+1,i,cur*10+i);
                }
            }
        };
        dfs(0,0,0);
        return ans;
    }
};
