/*
枚举右端点，如果枚举的元素小于等于前一个元素，则移动左指针，累计答案即可
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int l=0,r=0;r<n;r++){
            if(r&&nums[r-1]>=nums[r]) l=r;
            ans+=1LL*(r-l+1);
        }
        return ans;
    }
};
