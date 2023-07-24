/*
筛出所有质数，依次枚举即可
*/
class Solution {
public:
    static const int N=1e6+10;
    int u[N],prim[N],vis[N];
    int cnt=0;
    void Euler(int n){
        memset(u,0,sizeof u);
        memset(vis,0,sizeof vis);
        for(int i=2;i<=n;i++){
            if(!vis[i]) prim[++cnt]=i,u[i]=1;
            for(int j=1;1LL*i*prim[j]<=n;j++){
                vis[i*prim[j]]=1;
                if(i%prim[j]==0) break;
            }
        }
    }

    vector<vector<int>> findPrimePairs(int n) {
        Euler(n+1);
        vector<vector<int>> ans;
        for(int i=2;i<=n;i++){
            if(i>n-i) break;
            if(u[i]&&u[n-i]) ans.push_back({i,n-i});
            
        }
        return ans;
    }
};
