/*
排序后滑动窗口找最小值即可
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1e9;
        sort(nums.begin(),nums.end());
        for(int l=0,r=0;r<n;r++){
            if(r>=k-1) ans=min(ans,nums[r]-nums[l++]);
        }
        return ans;
    }
};
