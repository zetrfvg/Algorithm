/*
暴力枚举所有合法子数组
*/
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n-1;i++){
            int p=1;
            int j=i;
            while(j+1<n&&nums[j+1]-nums[j]==p) p*=-1,j++;
            ans=max(ans,j-i+1>1?j-i+1:-1);
        }
        return ans;
    }
};
