/*
简单BFS运用
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j]>0;
                if(grid[i][j]==2) q.push({i,j}),grid[i][j]=0;
            }
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                cnt++;
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m||!grid[xx][yy]) continue;
                    q.push({xx,yy});
                    grid[xx][yy]=0;
                }
            }
            if(!q.empty()) ans++;
        }
        return sum==cnt?ans:-1;
    }
};
