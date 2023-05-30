/*
双指针枚举右端点，找到最小的合法区间
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,ans=1e9;
        int n=nums.size();
        for(int l=0,r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l++];
            }
        }
        return ans==1e9?0:ans;
    }
};
