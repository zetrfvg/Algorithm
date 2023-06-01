/*
双指针枚举
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,cur=1;
        for(int l=0,r=0;r<n;r++){
            cur*=nums[r];
            while(l<=r&&cur>=k) cur/=nums[l++];
            ans+=r-l+1;
        }
        return ans;
    }
};
