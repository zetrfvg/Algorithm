/*
双指针+去重
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            int k=n-1,target=-nums[i];
            for(int j=i+1;j<k;){
                while(j<k&&nums[j]+nums[k]>target) k--;
                if(j==k) break;
                if(nums[j]+nums[k]==target) ans.push_back({nums[i],nums[j],nums[k]});
                int y=j;
                while(j<k&&nums[j]==nums[y]) j++;
            }
            int x=i;
            while(i<n&&nums[i]==nums[x]) i++;
        }
        return ans;
    }
};
