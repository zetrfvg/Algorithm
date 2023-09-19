/*
定义f[i][j]：二进制的第j位为1，且下标大于等于i的元素位置
枚举i，找到f[i][j]中最大的最远的元素位置即为i的答案
*/
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> f(n+1,vector<int>(31));
        for(int i=n-1;~i;i--){
            for(int j=0;j<=30;j++){
                f[i][j]=f[i+1][j];
                if(nums[i]&(1<<j)) f[i][j]=i;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int mx=i;
            for(int j=0;j<=30;j++) mx=max(mx,f[i][j]);
            ans[i]=mx-i+1;
        }
        return ans;
    }
};
