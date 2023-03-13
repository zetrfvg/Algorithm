/*
用一个哈希表来统计各个元素的个数
首先考虑对于元素x，存在cnt个，则选择删除x能获得的价值为x*cnt
同时，相邻的元素x-1，x+1均不可选

换句话说，要偷取的第x间屋子的价值为x*cnt，且相邻的屋子不可偷取
由此转换到了打家劫舍这一问题求解
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(mx+1,vector<int>(2,0));
        unordered_map<int,int> mp;
        for(auto c:nums) mp[c]++;
        dp[1][1]=mp[1];
        for(int i=2;i<=mx;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+i*mp[i];
        }
        return max(dp.back()[0],dp.back()[1]);
    }
};
