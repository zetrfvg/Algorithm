/*
状态定义：
dp[i]：以第i个元素结尾的最长子序列的长度
状态转移：
对于所有j<i且nums[j]<nums[i]，dp[i]=max(dp[i],dp[j]+1)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
