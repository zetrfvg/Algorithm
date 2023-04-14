/*
状态定义：
剩下的数组区间为[i,j]时，当前玩家与另一个玩家的分数之差的最大值
转移方程：
dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1])
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int i=n-1;~i;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};
