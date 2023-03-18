/*
状态定义：
dp[i]：以第i个元素结尾的最长子序列的长度
状态转移：
对于所有j<i且nums[j]<nums[i]，dp[i]=max(dp[i],dp[j]+1)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

/*
贪心+二分
维护一个递增的序列
枚举nums中的元素，在序列中二分查找找到第一个大于等于它的位置
用nums[i]去更新这个序列中这个位置的值
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> g;
        for(int i=0;i<n;i++){
            if(!g.size()||nums[i]>g.back()){
                g.push_back(nums[i]);
            }else{
                auto p=lower_bound(g.begin(),g.end(),nums[i])-g.begin();
                g[p]=nums[i];               
            }
        }
        return g.size();
    }
};
