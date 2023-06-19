/*
状态定义：
dp[i][j]：考虑前i个元素，模3值为j时最大的元素和
转移方程：
dp[i+1][(j+nums[i])%3]=max(dp[i][j]+nums[i]);
*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3));
        dp[0][1]=dp[0][2]=INT_MIN;
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i];
            for(int j=0;j<3;j++){
                dp[i+1][(j+nums[i])%3]=max(dp[i+1][(j+nums[i])%3],dp[i][j]+nums[i]);
            }
        }
        return dp[n][0];
    }
};
