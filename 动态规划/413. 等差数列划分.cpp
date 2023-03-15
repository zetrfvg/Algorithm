/*
定义状态：
dp[i]：表示以第i个元素结尾且长度至少为3的等差数列有多少个
转移方程：
如果第i-2,i-1,i三个元素能够组成一个等差数列，则dp[i]=dp[i-1]+1
否则dp[i]=0
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n<3) return 0;
        vector<int> dp(n,0);
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
                ans+=dp[i];
            }else{
                dp[i]=0;
            }
        }
        return ans;
    }
};
