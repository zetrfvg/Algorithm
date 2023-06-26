/*
前后缀枚举计算即可
*/
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long pre=0,suf=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();
        int ans=n-1,mn=1e9;
        for(int i=0;i<n;i++){
            pre+=nums[i],suf-=nums[i];
            int x=pre/(i+1),y=i==n-1?0:suf/(n-i-1);
            if(abs(x-y)<mn){
                mn=abs(x-y);
                ans=i;
            }
        }
        return ans;
    }
};
