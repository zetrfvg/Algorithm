/*
从左向右枚举所有长度为k的子数组按左端点的值执行减操作
减的过程中左端点不能为负数
枚举完之后检验最后k-1个数是否为0即可
*/
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        using ll=long long;
        vector<ll> pre(n);
        ll s=0;
        for(int i=0;i<=n-k;i++){
            if(nums[i]-s<0) return false;
            pre[i]=nums[i]-s;
            s+=1LL*nums[i]-s;
            if(i>=k-1) s-=pre[i-k+1];
        }
        for(int i=n-k+1;i<n;i++){
            if(nums[i]-s!=0) return false;
            if(i>=k-1) s-=pre[i-k+1];
        }
        return true;
    }
};
