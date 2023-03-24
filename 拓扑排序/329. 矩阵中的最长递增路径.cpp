/*
建图
对于两个相邻的点(a,b)与(c,d)，如果它们的值不相等
则从小的点向大的点连一条边
对整个图求拓扑排序的层数即为答案
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> g(n*m);
        vector<int> deg(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if(x<0||x>=n||y<0||y>=m||matrix[x][y]<=matrix[i][j]) continue;
                    g[i*m+j].push_back(x*m+y);
                    deg[x*m+y]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<n*m;i++) if(!deg[i]) q.push(i);
        int ans=0;
        while(!q.empty()){
            ans++;
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                for(auto y:g[x]) if(!--deg[y]) q.push(y);
            }
        }
        return ans;
    }
};
