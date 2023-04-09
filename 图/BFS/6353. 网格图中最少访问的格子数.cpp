/*
在bfs的过程中需要动态删掉已经更新过的点
用两个vector<set<int>> r,c
r[i]代表第i行还有哪些点需要更新，c[j]代表第j列还有哪些点需要更新
当前枚举到(x,y)时，我们用upper_bound来二分找到需要更新哪些点，然后加入队列，并把它们从该行删除掉
同样的方法用来更新同一列的点

时间复杂度：O(nmlog(nm))
*/
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<set<int>> r(n),c(m);
        vector<vector<int>> d(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                r[i].insert(j);
                c[j].insert(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        d[0][0]=1;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            auto yy=r[x].upper_bound(y);
            while(yy!=r[x].end()){
                if(*yy-y>grid[x][y]) break;
                if(d[x][*yy]==-1){
                    d[x][*yy]=d[x][y]+1;
                    q.push({x,*yy});
                }
                auto it=yy++;
                r[x].erase(it);
            }
            auto xx=c[y].upper_bound(x);
            while(xx!=c[y].end()){
                if(*xx-x>grid[x][y]) break;
                if(d[*xx][y]==-1){
                    d[*xx][y]=d[x][y]+1;
                    q.push({*xx,y});
                }
                auto it=xx++;
                c[y].erase(it);
            }
        }
        return d[n-1][m-1];
    }
};
