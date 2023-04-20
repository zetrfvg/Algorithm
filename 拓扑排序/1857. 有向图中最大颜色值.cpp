/*
拓扑排序+DP
对于某个点i，维护它一个状态：dp[i][j]表示从任意一个合法前驱走到i点的各个颜色的最大值，j∈[0,26]

*/
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> e(n);
        vector<int> deg(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            deg[p[1]]++;
        }
        vector<vector<int>> dp(n,vector<int>(26));
        int ans=1;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!deg[i]){
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y:e[x]){
                for(int i=0;i<26;i++){
                    dp[y][i]=max(dp[y][i],dp[x][i]+(i==colors[y]-'a'));
                    ans=max(ans,dp[y][i]);
                }
                if(!--deg[y]){
                    q.push(y);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(deg[i]){
                return -1;
            }
        }
        return ans;
    }
};
