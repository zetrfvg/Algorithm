/*
状态定义：
dp[i]：剩i堆石子是否是必胜态
转移方程：
如果存在x，使得dp[i-x]是必败态，那么dp[i]就是一个必胜态
*/
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squ;
        for(int i=1;i*i<=n;i++) squ.push_back(i*i);
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            for(auto &x:squ){
                if(i>=x){
                    if(!dp[i-x]){
                        dp[i]=1;
                        break;
                    }
                }else break;
            }
        }
        return dp[n];
    }
};
