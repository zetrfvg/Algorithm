/*
暴力枚举
*/
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        int n=nums.size();
        for(int len=1;len<=n;len++){
            for(int i=0,j=i+len-1;j<n;i++,j++){
                bool ok=nums[i]%2==0&&nums[i]<=threshold;
                for(int k=i+1;k<=j;k++){
                    if(nums[k]>threshold) ok=0;
                    if(nums[k]%2==nums[k-1]%2) ok=0;
                }
                if(ok) ans=max(ans,len);
            }
        }
        return ans;
    }
};
