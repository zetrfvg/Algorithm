/*
求出乘积为奇数的子数组数目ans，则答案为n*(n+1)/2-ans
双指针枚举右端点，如果右端点不为奇数则移动左指针，否则累加ans
*/
class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int l=0,r=0;r<n;r++){
            if(nums[r]&1) ans+=r-l+1;
            else l=r+1;
        }
        return 1LL*n*(n+1)/2-ans;
    }
};
