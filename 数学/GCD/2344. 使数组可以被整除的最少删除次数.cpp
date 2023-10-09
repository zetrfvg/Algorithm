/*
排序后找到最小能够整除gcd{numsDivide[j]}的nums[i]即可
*/
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=0;
        for(auto d:numsDivide) g=__gcd(g,d);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) if(g%nums[i]==0) return i;
        return -1;
    }
};
