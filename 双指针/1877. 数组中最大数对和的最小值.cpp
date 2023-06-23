/*
排序后从两端枚举
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int l=0,r=n-1;l<r;l++,r--){
            ans=max(ans,nums[l]+nums[r]);
        }
        return ans;
    }
};
