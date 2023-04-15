/*
最小生成树-Prim
*/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> vis(n),dis(n,1e9);
        auto calc=[&](int i,int j){
            return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
        };
        dis[0]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
            }
            ans+=dis[u];
            vis[u]=1;
            for(int j=0;j<n;j++){
                if(!vis[j]) dis[j]=min(dis[j],calc(u,j));
            }
        }
        return ans;
    }
};
