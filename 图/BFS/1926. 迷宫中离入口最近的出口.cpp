/*
BFS扩展找到最近的出口即可
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>> g(n,vector<int>(m,-1));
        g[entrance[0]][entrance[1]]=0;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||maze[xx][yy]=='+'||g[xx][yy]!=-1) continue;
                g[xx][yy]=g[x][y]+1;
                q.push({xx,yy});
                if(xx==0||xx==n-1||yy==0||yy==m-1){
                    return g[xx][yy];
                }
            }
        }
        return -1;
    }
};
