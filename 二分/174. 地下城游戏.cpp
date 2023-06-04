/*
二分答案，check的时候，凡是走到生命值为非正数的格子统统设为负无穷表示不可走。返回到终点的生命中是否大于0即可

也可以使用复杂度更优的dp来做
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l=1,r=1e9;
        int n=dungeon.size(),m=dungeon[0].size();
        auto check=[&](int st){
            auto g=dungeon;
            g[0][0]+=st;
            if(g[0][0]<=0) return false;
            for(int i=1;i<m;i++){
                g[0][i]+=g[0][i-1];
                if(g[0][i]<=0) g[0][i]=-1e9;
            }
            for(int i=1;i<n;i++){
                g[i][0]+=g[i-1][0];
                if(g[i][0]<=0) g[i][0]=-1e9;
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(g[i-1][j]<=0&&g[i][j-1]<=0) g[i][j]=-1e9;
                    else if(g[i-1][j]<=0) g[i][j]+=g[i][j-1];
                    else if(g[i][j-1]<=0) g[i][j]+=g[i-1][j];
                    else g[i][j]+=max(g[i-1][j],g[i][j-1]);
                }
            }
            return g[n-1][m-1]>0;
        };
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
