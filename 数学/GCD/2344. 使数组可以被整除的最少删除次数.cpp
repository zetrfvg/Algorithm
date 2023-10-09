/*
排序后找到最小能够整除gcd{numsDivide[j]}的nums[i]即可
*/
class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        long long g=0;
        for(auto d:numsDivide) g=gcd(g,d);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) if(g%nums[i]==0) return i;
        return -1;
    }
};
