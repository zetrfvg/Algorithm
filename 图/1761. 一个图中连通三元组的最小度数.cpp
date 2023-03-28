/*
bitset枚举三元环
*/
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<bitset<400>> g(n);
        vector<int> deg(n);
        for(auto p:edges){
            int x=p[0]-1,y=p[1]-1;
            g[x][y]=1,g[y][x]=1;
            deg[x]++,deg[y]++;
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!g[i][j]) continue;
                auto c=g[i]&g[j];
                for(int k=j+1;k<n;k++){
                    if(c[k]){
                        ans=min(ans,deg[i]+deg[j]+deg[k]-6);
                    }
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};
