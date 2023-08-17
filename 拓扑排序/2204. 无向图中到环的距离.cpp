/*
拓扑排序找出在环上的所有点，对环上的所有点跑一遍多源BFS即可
*/
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        int end=-1;
        vector<vector<int>> e(n);
        vector<int> deg(n),vis(n);
        for(auto &ed:edges){
            e[ed[0]].push_back(ed[1]);
            e[ed[1]].push_back(ed[0]);
            deg[ed[0]]++,deg[ed[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(deg[i]==1) q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis[x]=1;
            for(auto y:e[x]) if(--deg[y]==1) q.push(y);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++) if(!vis[i]) q.push(i),ans[i]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:e[x]){
                if(ans[y]!=-1) continue;
                ans[y]=ans[x]+1;
                q.push(y);
            }
        }
        return ans;
    }
};
