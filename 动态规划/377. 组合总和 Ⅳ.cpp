/*
定义状态：
dp[i]：选取若干元素的和为i时的排列数
状态转移：
对于一种排列以nums[j]结尾，那么dp[i]可由dp[i-nums[j]]转移而来
于是有dp[i]=Σdp[i-nums[j]]
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=target;i++){
            for(auto x:nums){
                if(i>=x) dp[i]+=dp[i-x];
            }
        }
        return dp[target];
    }
};
