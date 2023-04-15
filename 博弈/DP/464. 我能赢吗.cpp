/*
用st来表示哪些数被选过，cur表示当前被选的所有数的和
如果当前状态向后搜索只要存在一种胜利的方式，就是必胜态，否则就是必败态
*/
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal){
            return false;
        }
        vector<int> dp(1<<maxChoosableInteger);
        function<int(int,int)> dfs=[&](int st,int cur){
            if(dp[st]) return 1;
            for(int i=0;i<maxChoosableInteger;i++){
                if((st>>i)&1) continue;
                if(cur+i+1>=desiredTotal) return dp[st]=1;
                if(!dfs(st|(1<<i),cur+i+1)) return dp[st]=1;
            }
            return 0;
        };
        return dfs(0,0);
    }
};
