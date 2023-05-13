class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const auto &a,const auto &b){
            return abs(a)>abs(b);
        });
        for(int i=1;i<nums.size();i++){
            if(nums[i]+nums[i-1]==0){
                return abs(nums[i]);
            }
        }
        return -1;
    }
};
