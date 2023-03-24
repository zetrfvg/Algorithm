/*
首先排除各种无解的情况
数组总和为sum，令target=sum/2
如果我们从数组中选出若干元素且它们的和等于target，则剩下未选出的元素和也一定是target，满足两个分割子集的要求
于是我们要解决的问题为能否从nums中选出若干个元素，它们的和为target
状态定义：
dp[i][j]：前i个数是否存在和为j子集
转移方程：
如果nums[i]<=j：dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i]];
如果nums[i]>j：dp[i][j]=dp[i-1][j];
其中，
dp[i-1][j]的转移表示不选nums[i]
dp[i-1][j-nums[i]]的转移表示选nums[i]
二者只需至少一个为真，那么dp[i][j]为真
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n<1) return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int mx=*max_element(nums.begin(),nums.end());
        if(mx>sum/2) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=1;i<n;i++){
            int x=nums[i];
            for(int j=1;j<=target;j++){
                if(j>=x){
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-x];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};
