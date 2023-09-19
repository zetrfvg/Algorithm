/*
暴力简单模拟
*/
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        auto b=nums;
        int n=nums.size();
        sort(b.begin(),b.end());
        if(nums==b) return 0;
        for(int i=1;i<=n;i++){
            reverse(nums.begin(),nums.begin()+n-1);
            reverse(nums.begin(),nums.end());
            if(nums==b) return i;
        }
        return -1;
    }
};
