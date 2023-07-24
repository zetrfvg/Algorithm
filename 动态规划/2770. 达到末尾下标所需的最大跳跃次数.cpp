/*
状态定义：
dp[i]：跳到第i格所需的最小步数
转移方程：
dp[i]=max(dp[i],dp[j]+1)，其中abs(nums[i]-nums[j])<=target
*/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;~j;j--){
                if(abs(nums[i]-nums[j])<=target&&dp[j]!=-1) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return dp[n-1];
    }
};
