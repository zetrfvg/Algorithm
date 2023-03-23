/*
状态定义：
dp[i][0]：考虑以第i个数结尾，不翻转它的连续的1的个数
dp[i][1]：考虑以第i个数结尾，翻转它的连续的1的个数
转移方程：
if(nums[i-1]==1){
    dp[i][0]=dp[i-1][0]+1;
    dp[i][1]=dp[i-1][1]+1;
}else{
    dp[i][0]=0;
    dp[i][1]=dp[i-1][0]+1;
}
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(2));
        for(int i=1;i<=n;i++){
            if(nums[i-1]){
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
            }else{
                dp[i][0]=0;
                dp[i][1]=dp[i-1][0]+1;
            }
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};
