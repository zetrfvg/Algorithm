/*
我们求出它的前缀积l与后缀积r
对于第i个元素的答案，为l[i-1]*r[i+1]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n+1,1),r(n+1,1);
        for(int i=1;i<=n;i++){
            l[i]=l[i-1]*nums[i-1];
            r[n-i]=r[n-i+1]*nums[n-i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=l[i]*r[i+1];
        }
        return ans;
    }
};
