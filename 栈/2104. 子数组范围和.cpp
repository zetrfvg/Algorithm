/*
贡献法，统计每个数作为最大元素和最小元素分别出现在了多少个子数组中
以先找到每个数作为最大元素为例
枚举元素nums[i]，我们需要找到一个包含i最长的区间[l,r]，且nums[l-1]>nums[i]&&nums[r+1]>nums[i]
则nums[i]作为最大值的贡献为nums[i]*(i-l)*(r-i)
找到这个区间也即找到离nums[i]最近的大于它的元素，这是经典的单调栈应用场景
利用单调栈可以在O(n)的复杂度内找到nums[i]左右两边离它最近的大于它的元素，找到之后即可计算nums[i]的贡献

每个数作为最小元素的贡献大致相同，我们用前者的贡献和减去后者的贡献和即为答案
*/
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> mx,mn;
        int n=nums.size();
        long long ans=0;
        mx.push(-1),mn.push(-1);
        for(int i=0;i<n;i++){
            while(mx.top()!=-1&&nums[i]>nums[mx.top()]){
                int x=mx.top();
                mx.pop();
                ans+=1LL*(i-x)*(x-mx.top())*nums[x];
            }
            while(mn.top()!=-1&&nums[i]<nums[mn.top()]){
                int y=mn.top();
                mn.pop();
                ans-=1LL*(i-y)*(y-mn.top())*nums[y];
            }
            mx.push(i),mn.push(i);
        }
        while(mx.top()!=-1){
            int i=mx.top();
            mx.pop();
            ans+=1LL*(n-i)*(i-mx.top())*nums[i];
        }
        while(mn.top()!=-1){
            int i=mn.top();
            mn.pop();
            ans-=1LL*(n-i)*(i-mn.top())*nums[i];
        }
        return ans;
    }
};
