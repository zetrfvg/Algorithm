/*
我们首先对数组进行排序
因为子序列无需考虑元素的顺序性，我们回答每个询问，
基于贪心，要尽可能少的删除元素，并且希望这些元素尽可能的大
于是我们求nums的前缀和数组，对于每个询问，二分查找到最后一个小于等于它的位置即可

时间复杂度：O(nlogn+mlogn)
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int> ans(m);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        for(int i=0;i<m;i++){
            ans[i]=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
        }
        return ans;
    }
};
