/*
排序之后找相邻元素中差值最小的即可
*/
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=2e9;
        int n=nums.size();
        for(int i=1;i<n;i++){
            ans=min(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};
