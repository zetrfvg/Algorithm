/*
状态定义：
dp[i]：走到第i格的最大得分
转移方程：
dp[i]=nums[i]+max(dp[j])，j∈[i-k,i-1]

单调队列优化
用单调队列维护前k个状态中的最大值进行转移
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n);
        deque<int> q;
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
            while(!q.empty()&&i-q.front()>k) q.pop_front();
            if(!q.empty()) dp[i]+=dp[q.front()];
            while(!q.empty()&&dp[q.back()]<dp[i]) q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};
