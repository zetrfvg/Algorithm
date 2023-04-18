/*
两次多源BFS
对太平洋的边缘格子做一次BFS，看它们能被哪些点流到
对大西洋的边缘格子也做一次BFS，看哪些点能被流到
能被两次BFS都覆盖的点就是答案
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pa(n,vector<int>(m)),at(n,vector<int>(m));
        queue<pair<int,int>> q;
        function<void(int)> bfs=[&](int p){
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m||heights[xx][yy]<heights[x][y]) continue;
                    if(p&1&&pa[xx][yy]) continue;
                    else if(!(p&1)&&at[xx][yy]) continue;
                    if(p&1) pa[xx][yy]=1;
                    else at[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        };
        for(int i=0;i<m;i++){
            q.push({0,i});
            pa[0][i]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,0});
            pa[i][0]=1;
        }
        bfs(1);
        for(int i=0;i<m;i++){
            q.push({n-1,i});
            at[n-1][i]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,m-1});
            at[i][m-1]=1;
        }
        bfs(2);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pa[i][j]&&at[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
