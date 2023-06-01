/*
双指针枚举
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=1e9,cur=0,ok=0;
        for(int l=0,r=0;r<n;r++){
            cur+=nums[r];
            while(cur>=target){
                ok=1;
                cur-=nums[l++];
            }
            if(ok) ans=min(ans,r-l+2);
        }
        return ans==1e9?0:ans;
    }
};
