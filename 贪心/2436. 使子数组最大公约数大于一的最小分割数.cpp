/*
枚举nums[i]，求nums[i]与之前元素的gcd，如果前缀gcd=1，则在nums[i]左侧切割做一次分割，继续向后枚举
*/
class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        nums.push_back(1);
        int ans=0,d=0;
        for(int i=0;i<nums.size();i++){
            if(__gcd(nums[i],d)==1) ans++,d=nums[i];
            d=__gcd(nums[i],d);
        }
        return ans;
    }
};
