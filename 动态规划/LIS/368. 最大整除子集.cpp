/*
先排序
与LIS一样，这里的转移条件是nums[i]%nums[j]==0
然后逆推找到一组解即可
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n);
        int mxlen=0,ele=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]>mxlen){
                mxlen=dp[i];
                ele=nums[i];
            }
        }
        vector<int> ans;
        for(int i=n-1;~i;i--){
            if(dp[i]==mxlen&&ele%nums[i]==0){
                mxlen--;
                ele=nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
