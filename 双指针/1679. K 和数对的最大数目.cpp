/*
排序后双指针从两端枚举即可
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int l=0,r=n-1;l<r;){
            if(nums[l]+nums[r]>k) r--;
            else if(nums[l]+nums[r]<k) l++;
            else l++,r--,ans++;
        }
        return ans;
    }
};
