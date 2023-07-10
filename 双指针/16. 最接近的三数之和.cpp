/*
对于求nums[i]+nums[j]+nums[k]最接近target的组合
排序后枚举所有元素nums[i]，随后双指针枚举nums[j]和nums[k]，遍历所有可能的情况，能够找到最接近的组合
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-20000;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1,k=n-1;j<k;){
                int diff=nums[i]+nums[j]+nums[k]-target;
                if(abs(diff)<abs(ans-target)) ans=nums[i]+nums[j]+nums[k];
                if(diff>0) k--;
                else j++;
            }
        }
        return ans;
    }
};
