/*
双指针模拟
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int l=0,r=0,i=0;i<n;i+=2){
            while(nums[l]<0) l++;
            ans[i]=nums[l++];
            while(nums[r]>0) r++;
            ans[i+1]=nums[r++];
        }
        return ans;
    }
};
