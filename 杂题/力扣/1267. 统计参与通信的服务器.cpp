/*
记录每一行每一列的服务器数量，枚举各个服务器，若服务器所在行或列的服务器数量大于1，则说明该服务器可进行通信
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n),col(m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++,col[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&(row[i]>1||col[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
