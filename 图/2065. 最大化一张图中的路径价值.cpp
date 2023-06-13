/*
观察数据可知，递归的深度不超过10，点的度数不超过4，最坏的情况即为4^10
因此考虑暴搜所有路径即可
*/
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>> e(n);
        for(auto &p:edges){
            e[p[0]].push_back({p[1],p[2]});
            e[p[1]].push_back({p[0],p[2]});
        }
        int ans=0;
        function<void(int,int,int)> dfs=[&](int x,int time,int cur){
            if(time>maxTime) return;
            cur+=values[x];
            int tmp=values[x];
            values[x]=0;
            if(!x) ans=max(ans,cur);
            for(auto &[y,w]:e[x]){
                dfs(y,time+w,cur);
            }
            values[x]=tmp;
        };
        dfs(0,0,0);
        return ans;
    }
};
