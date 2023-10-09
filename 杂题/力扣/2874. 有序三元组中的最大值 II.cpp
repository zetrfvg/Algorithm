/*
对于i<j<k，求max{(nums[i]-nums[j])*nums[k]}
枚举j，维护前缀最大的nums[i]-nums[j]差值，维护前缀最大值，顺序遍历找到答案
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int mx=0,diff=0;
        for(auto c:nums){
            ans=max(ans,1LL*diff*c);
            diff=max(diff,mx-c);
            mx=max(mx,c);
        }
        return ans;
    }
};
