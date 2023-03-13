class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges){
        vector<int> ans(n-1,0);
        vector<vector<int>> g(n);
        for(auto p:edges){
            g[p[0]-1].push_back(p[1]-1);
            g[p[1]-1].push_back(p[0]-1);
        }
        auto bfs=[&](int st){
            int res=0;
            for(int i=n-1;~i;i--){
                if((st>>i)&1){
                    vector<int> vis(n,0);
                    queue<int> q;
                    int p=0;
                    q.push(i);
                    vis[i]=1;
                    int len=0;
                    while(!q.empty()){
                        int sz=q.size();
                        while(sz--){
                            int x=q.front();
                            p|=(1<<x);
                            q.pop();
                            for(auto y:g[x]){
                                if(!((st>>y)&1)) continue;
                                if(vis[y]) continue;
                                vis[y]=1;
                                q.push(y);
                            }
                        }
                        len++;
                    }
                    if(p==st) res=max(len,res);
                    else return 0;
                }
            }
            return res-1;
        };
        for(int i=1;i<(1<<n);i++){
            int k=bfs(i);
            if(k>0) ans[k-1]++;
        }
        return ans;
    }
};
