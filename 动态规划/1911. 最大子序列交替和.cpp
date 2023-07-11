/*
状态定义：
dp[i][0]：以第i个元素结尾作为偶数下标时的最大子序列和
dp[i][1]：以第i个元素结尾作为奇数下标时的最大子序列和
转移方程：
dp[i][0]=max(dp[i][0],dp[i-1][1]+nums[i])
dp[i][1]=max(dp[i][1],dp[i-1][0]-nums[i])
这里使用了滚动数组进行优化
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long a=nums[0],b=0;
        for(int i=0;i<n;i++){
            a=max(a,b+nums[i]);
            b=max(b,a-nums[i]);
        }
        return max(a,b);
    }
};
