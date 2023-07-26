/*
破环成链
nums中1的个数为s
枚举所有长度为s的区间，区间中0的个数即为要操作的次数，取最小即可
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int s=count(nums.begin(),nums.end(),1);
        if(!s) return 0;
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        int ans=1e9,cnt=0;
        for(int i=0;i<2*n;i++){
            cnt+=nums[i]==0;
            if(i>=s-1){
                ans=min(ans,cnt);
                cnt-=nums[i-s+1]==0;
            }
        }
        return ans;
    }
};
