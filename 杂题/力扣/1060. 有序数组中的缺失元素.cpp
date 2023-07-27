/*
线性扫描，枚举两个数之间差多少个数，直到总数超过k为止
*/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int s=0;
        for(int i=1;i<nums.size();i++){
            int d=nums[i]-nums[i-1];
            if(s+d-1<k) s+=d-1;
            else return nums[i-1]+k-s;
        }
        return nums.back()+k-s;
    }
};
