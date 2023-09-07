/*
排序后暴力枚举j,k，在j之前的序列中二分找到最大的i，则该j,k对应满足条件的三元组有i+1组
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]+nums[0]<target){
                    int l=0,r=i-1;
                    while(l<r){
                        int m=(l+r+1)>>1;
                        if(nums[i]+nums[j]+nums[m]<target) l=m;
                        else r=m-1;
                    }
                    ans+=l+1;
                }
            }
        }
        return ans;
    }
};
