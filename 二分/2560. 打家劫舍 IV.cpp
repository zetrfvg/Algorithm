/*
二分答案
check：基于贪心，从左到右依次枚举房子，能偷就偷，不会使情况变劣
*/
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=1e9;
        int n=nums.size();
        auto check=[&](int m){
            int res=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m) res++,i++;
            }
            return res>=k;
        };
        while(l<r){
            int m=(l+r)>>1;
            if(check(m)) r=m;
            else l=m+1;
        }
        return l;
    }
};
