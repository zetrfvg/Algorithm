/*
简单滑窗模拟
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-100000,s=0;
        for(int l=0,r=0;r<nums.size();r++){
            s+=nums[r];
            if(r>=k-1){
                ans=max(ans,s/k);
                s-=nums[l++];
            }
        }
        return ans;
    }
};
