/*
考虑当前还剩下石子的区间为[i,n]，不论当前玩家是谁，都要拿尽可能多的石子
如果剩下石子的堆数小于等于2*M，则全部拿走最优，否则要进行搜索，拿多少石子时才能最优
因为存在重复计算，所以使用记忆化搜索来记录搜索过的状态
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        for(int i=n-2;~i;i--){
            piles[i]+=piles[i+1];
        }
        int dp[n][n+1];
        memset(dp,-1,sizeof dp);
        function<int(int,int)> dfs=[&](int i,int M){
            if(i+M*2>=n) return piles[i];
            if(dp[i][M]!=-1) return dp[i][M];
            int &res=dp[i][M],mn=1e9;
            for(int j=1;j<=M*2;j++){
                mn=min(mn,dfs(i+j,max(M,j)));
            }
            return res=piles[i]-mn;
        };
        return dfs(0,1);
    }
};
