/*
模拟
*/
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        for(int l=0,r=nums.size()-1;l<=r;l++,r--){
            ans+=nums[r];
            if(l!=r){
                long long t=1;
                while(nums[r]) t*=10,nums[r]/=10;
                ans+=1LL*nums[l]*t;
            }
        }
        return ans;
    }
};
