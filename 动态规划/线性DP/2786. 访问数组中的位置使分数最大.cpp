/*
状态定义：
a：以奇数结尾的最大得分
b：以偶数结尾的最大得分
*/
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long ans=0;
        long long a=-1e16,b=-1e16;
        nums[0]&1?a=nums[0]:b=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]&1){
                a=max(a,b-x)+nums[i];
            }else{
                b=max(b,a-x)+nums[i];
            }
        }
        return max(a,b);
    }
};
