/*
中位数贪心
首先存下所有的1的位置，然后滑动窗口枚举所有连续的k个1的窗口
这里基于贪心，把所有的1放置到中位数(中间那个1的位置)的两边最优，枚举窗口计算最小答案即可
*/
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> p;
        for(int i=0;i<n;i++) if(nums[i]) p.push_back(i-p.size());
        int m=p.size();
        vector<int> s(m+1);
        for(int i=0;i<m;i++) s[i+1]=s[i]+p[i];
        int ans=2e9;
        for(int i=0;i<=m-k;i++){
            ans=min(ans,s[i]+s[i+k]-s[i+k/2]*2-p[i+k/2]*(k%2));
        }
        return ans;
    }
};
