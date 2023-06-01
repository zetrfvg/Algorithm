/*
滑动窗口枚举所有长为2*k+1的区间即可
特判k==0和n<2*k+1的情况
*/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(!k) return nums;
        int n=nums.size();
        vector<int> ans(n,-1);
        if(n<k*2+1) return ans;
        long long sum=0;
        for(int l=0,r=0;r<n;r++){
            sum+=nums[r];
            if(r>=2*k){
                ans[r-k]=sum/(2*k+1);
                sum-=nums[l++];
            }
        }
        return ans;
    }
};
