/*
马走日字搜索题
*/
class Solution {
public:
    int dx[8]={-1,-2,-2,-1,1,2,2,1};
    int dy[8]={-2,-1,1,2,2,1,-1,-2};
    vector<vector<int>> tourOfKnight(int n, int m, int r, int c) {
        vector<vector<int>> ans(n,vector<int>(m,-1));
        function<bool(int,int,int)> dfs=[&](int x,int y,int idx){
            ans[x][y]=idx;
            if(idx==n*m-1) return true;
            for(int i=0;i<8;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||ans[xx][yy]!=-1) continue;
                if(dfs(xx,yy,idx+1)) return true;
            }
            ans[x][y]=-1;
            return false;
        };
        dfs(r,c,0);
        return ans;
    }
};
