/*
一个元素左移k位，一定优于多个元素左移
枚举nums中的元素nums[i]，将nums[i]左移k位，同时或上它的前后缀，返回最大值即可
*/
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long t=0;
        int j=0;
        int n=nums.size();
        vector<int> pre(n),suf(n);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]|nums[i-1];
        }
        for(int i=n-2;~i;i--){
            suf[i]=suf[i+1]|nums[i+1];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long l=pre[i],r=suf[i];
            ans=max(ans,l|r|((1LL*nums[i])<<k));
        }
        return ans;
    }
};
