/*
对于一个黑格子，包含它的2×2方格有四个，考虑枚举这四个2×2方格的左上角的点，用一个点来表示一个2×2方格
计算出各个2×2方格中有多少个黑格子，这里用一个哈希表来记录每个2×2方格是否被访问过即可
*/
class Solution {
public:
    int dx[4]={0,0,1,1};
    int dy[4]={0,1,0,1};
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& coordinates) {
        using ll=long long;
        const ll D=1e5+10;
        unordered_set<ll> st,vis;
        for(auto &p:coordinates){
            st.insert(1LL*p[0]*D+p[1]);
        }
        vector<long long> ans(5);
        for(auto &p:coordinates){
            for(auto &i:{-1,0}){
                for(auto &j:{-1,0}){
                    int x=p[0]+i,y=p[1]+j;
                    if(x<0||x>=n-1||y<0||y>=m-1||vis.count(1LL*x*D+y)) continue;
                    vis.insert(1LL*x*D+y);
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int xx=x+dx[k],yy=y+dy[k];
                        cnt+=st.count(1LL*xx*D+yy);
                    }
                    ans[cnt]++;
                }
            }
        }
        ans[0]=1LL*(n-1)*(m-1)-ans[1]-ans[2]-ans[3]-ans[4];
        return ans;
    }
};
