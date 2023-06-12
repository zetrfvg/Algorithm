/*
计算nums的和sum，求sum与目标值goal之差的绝对值delta
每次贪心的选x，使abs(x)=limit，那么总共要选(delta+limit-1)/limit个
*/
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long delta=abs(sum-goal);
        return (delta+limit-1)/limit;
    }
};
