/*
从小到大枚举元素作为子数组的左端点，同时维护一个最远值
顺序枚举能保证每次找到的右端点一定不大于左端点且最远
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> ids(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](const auto &i,const auto &j){
            return nums[i]<nums[j];
        });
        int p=ids[0],ans=0;
        for(int i=1;i<n;i++){
            p=max(p,ids[i]);
            if(p!=ids[i]&&nums[ids[i]]!=nums[p]){
                ans=max(ans,p-ids[i]+1);
            }
        }
        return ans;
    }
};
