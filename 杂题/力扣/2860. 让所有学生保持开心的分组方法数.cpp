/*
排序后判断情况，case很多需要细想
*/
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]>0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<i+1){
                if(i!=n-1&&nums[i+1]>i+1) ans++;
                else if(i==n-1) ans++;
            }
        }
        return ans;
    }
};
