/*
模拟BFS即可，细节较多
*/
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[start[0]][start[1]]=0;
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                int cnt=0;
                while(xx>=0&&xx<n&&yy>=0&&yy<m&&!maze[xx][yy]){
                    xx+=dx[i],yy+=dy[i];
                    cnt++;
                }
                if(dis[x][y]+cnt<dis[xx-dx[i]][yy-dy[i]]){
                    dis[xx-dx[i]][yy-dy[i]]=dis[x][y]+cnt;
                    q.push({xx-dx[i],yy-dy[i]});
                }
            }
        }
        return dis[destination[0]][destination[1]]==1e9?-1:dis[destination[0]][destination[1]];
    }
};
