/*
经典二分查找
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<int> ans(2,-1);
        while(l<r){
            int m=(l+r)>>1;
            if(nums[m]<target) l=m+1;
            else r=m;
        }
        if(l<n&&nums[l]==target) ans[0]=l;
        l=0,r=n-1;
        while(l<r){
            int m=(l+r+1)>>1;
            if(nums[m]>target) r=m-1;
            else l=m;
        }
        if(l<n&&nums[l]==target) ans[1]=l;
        return ans;
    }
};
