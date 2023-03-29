/*
拓扑排序之后剩下的点构成若干个环
找到最长的一个即可
*/
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> deg(n),vis(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                deg[edges[i]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!deg[i]){
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int y=edges[x];
            if(y!=-1&&!--deg[y]){
                q.push(y);
                vis[y]=1;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int x=i,cur=0;
                while(!vis[x]){
                    ++cur;
                    vis[x]=1;
                    x=edges[x];
                }
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};
