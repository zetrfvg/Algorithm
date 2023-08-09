/*
贪心，排序后依次从小到大构造数字，计算操作次数
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num=nums[0],ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=num) ans+=num-nums[i]+1;
            num=max(num+1,nums[i]);
        }
        return ans;
    }
};
