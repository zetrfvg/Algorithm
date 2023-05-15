/*
按题意BFS即可
*/
class Solution {
public:
    int dx[3]={-1,0,1};
    int dy[3]={1,1,1};
    int maxMoves(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> d(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            q.push({i,0});
            d[i][0]=0;
        }
        int ans=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            ans=max(ans,d[x][y]);
            for(int i=0;i<3;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||d[xx][yy]!=-1||g[xx][yy]<=g[x][y]){
                    continue;
                }
                d[xx][yy]=d[x][y]+1;
                q.push({xx,yy});
            }
        }
        return ans;
    }
};
