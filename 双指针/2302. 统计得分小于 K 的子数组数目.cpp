/*
双指针枚举右端点，如果区间和*区间长小于k，那么以当前元素为右端点满足条件的子数组数组等于区间长度
当区间和*区间长不小于k时移动左指针
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,sum=0;
        for(int l=0,r=0;r<nums.size();r++){
            sum+=nums[r];
            while(l<=r&&1LL*sum*(r-l+1)>=k){
                sum-=nums[l++];
            }
            ans+=max(0,r-l+1);
        }
        return ans;
    }
};
