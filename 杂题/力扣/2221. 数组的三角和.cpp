/*
模拟即可
*/
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> tmp;
            for(int i=1;i<nums.size();i++){
                tmp.push_back((nums[i]+nums[i-1])%10);
            }
            nums=tmp;
        }
        return nums[0];
    }
};
