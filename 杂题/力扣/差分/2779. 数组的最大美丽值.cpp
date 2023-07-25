/*
对于一个元素nums[i]，它可以变为[nums[i]-k,nums[i]+k]中的任意一个数
因此维护一个值域数组，对于每个nums[i]，它为[nums[i]-k,nums[i]+k]都可以贡献1，则对这个区间进行+1的操作，这里用差分数组实现即可
最后枚举值域中数量最多的值即可
*/
class Solution {
public:
    int f[200010];
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        memset(f,0,sizeof f);
        for(int i=0;i<n;i++){
            f[max(0,nums[i]-k)]++;
            f[nums[i]+k+1]--;
        }
        int ans=1;
        for(int i=1;i<=200000;i++){
            f[i]+=f[i-1];
            ans=max(ans,f[i]); 
        }
        return ans;
    }
};
