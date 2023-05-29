/*
双指针
我们同样枚举右端点r，因为一个右端点可能对应多个左端点。注意到一个右端点能够对应的所有左端点一定是连续的
因此考虑左指针维护的不是端点，而是一端区间[l1,l2]
其中l1到r是以r为右端点，区间中元素有k种的最远的左端点
而l2到r则是以r为右端点，区间中元素有k-1种的最远的左端点
l2-l1即为以r为右端点，区间中有k种元素的子数组有多少个
时间复杂度：O(n)
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> more(20010),less(20010);
        int c1=0,c2=0;
        int n=nums.size();
        int ans=0;
        for(int l1=0,l2=0,r=0;r<n;r++){
            if(!more[nums[r]]) c1++;
            if(!less[nums[r]]) c2++;
            more[nums[r]]++,less[nums[r]]++;
            while(c1>k){
                if(!--more[nums[l1]]) c1--;
                l1++;
            }
            while(c2>k-1){
                if(!--less[nums[l2]]) c2--;
                l2++;
            }
            if(c1==k) ans+=l2-l1;
        }
        return ans;
    }
};
