/*
二分+滑窗
二分子数组的和m，再滑窗判断有多少个子数组满足和小于m
*/
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        auto check=[&](int m){
            int res=0,s=0;
            for(int l=0,r=0;r<nums.size();r++){
                s+=nums[r];
                while(s>m) s-=nums[l++];
                res+=(r-l+1);
            }
            return res<k;
        };
        while(l<r){
            int m=(l+r)>>1;
            if(check(m)) l=m+1;
            else r=m;
        }
        return l;
    }
};
