/*
O(n^3)枚举即可
*/
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans+=nums[i]!=nums[j]&&nums[i]!=nums[k]&&nums[j]!=nums[k];
                }
            }
        }
        return ans;
    }
};
