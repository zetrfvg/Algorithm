/*
模拟题
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        auto get=[&](int x){
            int res=0;
            while(x){
                res=max(res,x%10);
                x/=10;
            }
            return res;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(get(nums[i])==get(nums[j])) ans=max(ans,nums[i]+nums[j]);
            }
        }
        return ans;
    }
};
