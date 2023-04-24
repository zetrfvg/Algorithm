/*
因为值域不大
因此可以使用滑动窗口暴力计数
*/
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans,cnt(51);
        for(int i=0;i<n;i++){
            if(i>=k) cnt[-min(nums[i-k],0)]--;
            cnt[-min(nums[i],0)]++;
            if(i>=k-1){
                int tot=0;
                for(int i=50;~i;i--){
                    tot+=cnt[i];
                    if(tot>=x){
                        ans.push_back(-i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
