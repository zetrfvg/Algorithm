/*
枚举所有相邻的1之间0的个数，累乘起来即可
*/
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),1)==0) return 0;
        int l=0,r=nums.size()-1;
        int n=nums.size();
        while(l<n&&nums[l]==0) l++;
        while(~r&&nums[r]==0) r--;
        const int mod=1e9+7;
        int cnt=0,ans=1;
        for(int i=l+1;i<=r;i++){
            if(!nums[i]) cnt++;
            else{
                ans=1LL*ans*(cnt+1)%mod;
                cnt=0;
            }
        }
        return ans;
    }
};
