/*
双指针枚举右端点，如果区间中存在重复元素则移动左指针
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> v(10010);
        int ans=0,sum=0;
        for(int l=0,r=0;r<nums.size();r++){
            sum+=nums[r];
            ++v[nums[r]];
            while(v[nums[r]]>1) v[nums[l]]--,sum-=nums[l++];
            ans=max(ans,sum);
        }
        return ans;
    }
};
