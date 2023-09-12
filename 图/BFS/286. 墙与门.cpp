/*
简单多源BFS
*/
class Solution {
public:
    static const int inf=2147483647;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size(),m=rooms[0].size();
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!rooms[i][j]){
                    q.push({0,i,j});
                }
            }
        }
        while(!q.empty()){
            auto [d,x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||rooms[xx][yy]!=inf) continue;
                rooms[xx][yy]=d+1;
                q.push({d+1,xx,yy});
            }
        }
    }
};
