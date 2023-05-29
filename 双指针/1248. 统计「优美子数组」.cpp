/*
双指针右指针枚举右端点，而左指针维护的则是一段区间[l1,l2]
其中[l1,r]是以r为右端点，有k个奇数的最长子数组；
而[l2,r]是以r为右端点，有k-1个奇数的最长子数组
那么l2-l1即等于以r为右端点，有k个奇数的子数组的个数
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int c1=0,c2=0;
        for(int l1=0,l2=0,r=0;r<nums.size();r++){
            c1+=(nums[r]&1);
            c2+=(nums[r]&1);
            while(c1>k) c1-=(nums[l1++]&1);
            while(c2>k-1) c2-=(nums[l2++]&1);
            if(c1==k) ans+=l2-l1;
        }
        return ans;
    }
};
