/*
状态定义：
dp[i]表示以nums[i]结尾最大的区间和
转移方程：
dp[i]=max(dp[i-1]+nums[i],nums[i])
每次考虑是否把nums[i]加入到前一段区间中去，加不加取决于状态dp[i-1]是不是负数

与很多线性dp一样，可以用滚动数组来优化空间复杂度
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),ans=nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
