/*
定义状态：
dp[i][0]：以i结尾乘积为负数的最长子数组的长度
dp[i][1]：以i结尾乘积为正数的最长子数组的长度
转移方程：
1、nums[i]==0时：
以i结尾的子数组乘积一定为0
dp[i][0]=dp[i][1]=0
2、nums[i]>0时：
dp[i][1]=dp[i-1][1]+1
dp[i][0]=dp[i-1][0]>0?dp[i-1][0]+1:0;
3、nums[i]<0时：
dp[i][0]=dp[i-1][1]+1;
dp[i][1]=dp[i-1][0]>0?dp[i-1][0]+1:0;
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        if(nums[0]>0) dp[0][1]=1;
        if(nums[0]<0) dp[0][0]=1;
        int ans=dp[0][1];
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                dp[i][0]=dp[i][1]=0;
            }else if(nums[i]>0){
                dp[i][1]=dp[i-1][1]+1;
                dp[i][0]=dp[i-1][0]>0?dp[i-1][0]+1:0;
            }else{
                dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=dp[i-1][0]>0?dp[i-1][0]+1:0;
            }
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};
