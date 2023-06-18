/*
状态定义：
dp[i][j]：已经放置了集合为i的数字，最后放的一个数为j的排列数
*/
class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(1<<n,vector<int>(n));
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int ii=i^(1<<j);
                    if(!ii){
                        dp[i][j]=1;
                        break;
                    }
                    int p=__builtin_popcount(i);
                    for(int jj=0;jj<n;jj++){
                        if(ii&(1<<jj)&&((jj+1)%p==0||p%(jj+1)==0)){
                            dp[i][j]+=dp[ii][jj];
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) ans+=dp[(1<<n)-1][i];
        return ans;
    }
};
