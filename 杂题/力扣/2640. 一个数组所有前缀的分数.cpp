/*
前缀和模拟即可
*/
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size(),mx=0;
        vector<long long> ans(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            ans[i]=1LL*nums[i]+mx;
            if(i) ans[i]+=ans[i-1];
        }
        return ans;
    }
};
