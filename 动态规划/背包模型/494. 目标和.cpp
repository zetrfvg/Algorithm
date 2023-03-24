/*
总和为sum，目标值为target，则要减去的值为neg=(sum-target)/2；
题目转化为从nums的子序列中，和为neg的数量
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int diff=sum-target;
        if(diff<0||diff%2!=0) return 0;
        int neg=diff/2;
        vector<vector<int>> dp(n+1,vector<int>(neg+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=neg;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j){
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][neg];
    }
};
