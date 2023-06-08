/*
暴力搜索每个位置放的方块，从大到小枚举方块
*/
class Solution {
public:
    int tilingRectangle(int n, int m) {
        int ans=n*m;
        vector<vector<bool>> g(n,vector<bool>(m,0));
        auto check=[&](int x,int y,int d){
            for(int i=0;i<d;i++){
                if(count(g[x+i].begin()+y,g[x+i].begin()+y+d,1)) return false;
            }
            return true;
        };
        function<void(int,int,int)> dfs=[&](int x,int y,int cnt){
            if(cnt>=ans) return;
            if(x>=n){
                ans=min(ans,cnt);
                return;
            }
            if(y>=m){
                dfs(x+1,0,cnt);
                return;
            }
            if(g[x][y]){
                dfs(x,y+1,cnt);
                return;
            }
            for(int d=min(n-x,m-y);d&&check(x,y,d);d--){
                for(int i=0;i<d;i++){
                    fill(g[x+i].begin()+y,g[x+i].begin()+y+d,1);
                }
                dfs(x,y+d,cnt+1);
                for(int i=0;i<d;i++){
                    fill(g[x+i].begin()+y,g[x+i].begin()+y+d,0);
                }
            }
        };
        dfs(0,0,0);
        return ans;
    }
};
