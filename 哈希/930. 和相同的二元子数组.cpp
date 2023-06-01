/*
求前缀和数组
枚举所有前缀和s[i]
如果之前枚举的前缀和中有cnt个等于s[i]-goal，则以i为右端点的合法的子数组有cnt个，这里用哈希表计数维护
累计答案即可
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> s(n+1);
        for(int i=0;i<n;i++) s[i+1]=s[i]+nums[i];
        unordered_map<int,int> g;
        int ans=0;
        for(int i=0;i<=n;i++){
            ans+=g[s[i]-goal];
            g[s[i]]++;
        }
        return ans;
    }
};
