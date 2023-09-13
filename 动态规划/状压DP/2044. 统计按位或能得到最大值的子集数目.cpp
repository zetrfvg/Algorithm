/*
二进制枚举的优化
状态定义dp[i]：集合为i的元素的位或值
转移方程dp[i]=dp[i^(1<<j)]|nums[j]，j为i中的最低位的1的位置，实际上，j的取值只要i中的该位上为1都可以取
*/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0,mx=0,n=nums.size();
        unordered_map<int,int> p;
        for(int i=0;i<n;i++){
            mx|=nums[i];
            p[1<<i]=i;
        }
        vector<int> dp(1<<n);
        for(int i=1;i<(1<<n);i++){
            dp[i]=dp[i^(i&(-i))]|nums[p[i&(-i)]];
            ans+=dp[i]==mx;
        }
        return ans;
    }
};
