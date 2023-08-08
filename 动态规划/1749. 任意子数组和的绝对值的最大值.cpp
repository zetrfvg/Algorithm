/*
pos记录以nums[i]为右端点子数组和的最大正数
neg记录以nums[i]为右端点子数组和的最小负数
枚举nums[i]的过程中寻找最大值即可
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0,pos=0,neg=0;
        for(auto x:nums){
            pos=max(0,pos+x);
            neg=min(0,neg+x);
            ans=max({ans,pos,-neg});
        }
        return ans;
    }
};
