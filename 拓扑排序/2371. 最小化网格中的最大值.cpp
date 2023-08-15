/*
每一行排序后，每个元素向其后继元素连一条边
同理，每一列排序后，每个元素也向其后继元素连一条
建图完成后，按按拓扑序对网格图中的格子升序赋值即可
*/
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n,-1),col(m,-1);
        vector<array<int,3>> e;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                e.push_back({grid[i][j],i,j});
            }
        }
        sort(e.begin(),e.end());
        vector<vector<int>> edge(n*m);
        vector<int> deg(n*m);
        for(auto [x,i,j]:e){
            if(row[i]!=-1){
                edge[i*m+row[i]].push_back(i*m+j);
                deg[i*m+j]++;
            }
            if(col[j]!=-1){
                edge[col[j]*m+j].push_back(i*m+j);
                deg[i*m+j]++;
            }
            row[i]=j,col[j]=i;
        }
        queue<int> q;
        for(int i=0;i<n*m;i++) if(!deg[i]) q.push(i);
        for(int i=1;!q.empty();i++){
            int sz=q.size();
            while(sz--){
                auto pos=q.front();
                q.pop();
                int x=pos/m,y=pos%m;
                grid[x][y]=i;
                for(auto t:edge[pos]){
                    if(!--deg[t]) q.push(t);
                }
            }
        }
        return grid;
    }
};
