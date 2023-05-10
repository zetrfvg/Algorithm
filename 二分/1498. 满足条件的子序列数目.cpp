/*
二分＋+快速幂
因为子序列与顺序无关，我们对数组进行排序
枚举元素nums[i]作为序列的最小值，我们可以二分找到满足条件的最大值nums[j]
那么满足最小值为nums[i]，最大值为nums[j]的子序列个数为pow(2,j-i-1)个，套上快速幂即可
时间复杂度：O(nlog^2n)
*/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod=1e9+7;
        sort(nums.begin(),nums.end());
        auto pow=[&](long long x){
            long long a=2,res=1;
            while(x){
                if(x&1) res=res*a%mod;
                a=a*a%mod;
                x>>=1;
            }
            return res;
        };
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]*2>target) break;
            auto p=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin()-1;
            ans=(ans+pow(p-i))%mod;
        }
        return ans;
    }
};
