/*
bitset来枚举连通块中的点连的边是否一致
*/
class Solution {
public:
    bitset<54> f[54];
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<int> vis(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            f[a][b]=1,f[b][a]=1;
        }
        for(int i=0;i<n;i++){
            f[i][i]=1;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                bool ok=1;
                for(int j=0;j<n;j++){
                    if(f[i][j]){
                        ok&=f[i]==f[j];
                        vis[j]=1;
                    }
                }
                ans+=ok;
            }
        }
        return ans;
    }
};
