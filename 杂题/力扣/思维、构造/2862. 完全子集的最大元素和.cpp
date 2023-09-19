/*
枚举下标i，其中包含i的一个完全子集i*1²,i*2²,i*3²······，累加该子集更新答案
容易想到，这样的枚举不会漏掉最大的答案
*/
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long cur=0;
            for(int j=1;1LL*i*j*j<=n;j++){
                cur+=nums[i*j*j-1];
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
