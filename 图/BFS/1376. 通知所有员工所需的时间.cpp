/*
标准的树遍历
*/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> e(n);
        for(int i=0;i<n;i++){
            if(i!=headID){
                e[manager[i]].push_back(i);
            }
        }
        int ans=0;
        function<void(int,int)> dfs=[&](int x,int time){
            ans=max(ans,time);
            for(auto y:e[x]){
                dfs(y,time+informTime[x]);
            }
        };
        dfs(headID,0);
        return ans;
    }
};
