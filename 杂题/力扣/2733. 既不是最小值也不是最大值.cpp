/*
元素互不相同，对前三个数排序，返回中间那个数即可
*/
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<3) return -1;
        sort(nums.begin(),nums.begin()+3);
        return nums[1];
    }
};
