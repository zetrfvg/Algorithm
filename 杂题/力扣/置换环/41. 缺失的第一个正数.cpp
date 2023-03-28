/*
两次遍历
第一次遍历把每个元素对号入座，即元素i放到第i个位置上（如果元素不在[1,n]的范围内，不置换；如果当前位置已经对应，不置换；如果目标位置已经对应，不置换）
第二次遍历找到第一个不对应位置上的元素即可
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]<=n&&nums[i]>0&&nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]) swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
