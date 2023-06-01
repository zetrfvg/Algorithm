/*
状态定义：
dp[i]：以第i个数结尾的子序列中的最大和
转移方程：
dp[i]=nums[i]+max(0,dp[j])，其中i-j<=k
复杂度O(nk)

因为dp[i]是通过j∈[i-k,i-1]中最大的dp[j]转移而来，因此考虑单调队列优化
单调队列递减，如果队头元素和i相差距离超过k，则弹出队头
此时通过队头元素进行状态转移
弹出队尾小于dp[i]的元素
dp[i]入队
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
            while(!q.empty()&&i-q.front()>k) q.pop_front();
            if(!q.empty()) dp[i]=max(dp[q.front()],0)+nums[i];
            while(!q.empty()&&dp[i]>dp[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
