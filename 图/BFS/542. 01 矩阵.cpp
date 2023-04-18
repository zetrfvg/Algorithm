/*
多源BFS
要求每个1到最近的0的距离，反过来对整体0进行BFS去覆盖1即可，这个覆盖一定是由近及远的
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||ans[xx][yy]!=-1) continue;
                ans[xx][yy]=ans[x][y]+1;
                q.push({xx,yy});
            }
        }
        return ans;
    }
};
