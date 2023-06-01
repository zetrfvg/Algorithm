/*
一个长度为k的子数组最多翻转一次
我们枚举所有长为k的子数组的左端点，如果左端点是0，我们就翻转它，用cnt来维护当前元素的翻转的次数
如果位置i是0，则需要翻转奇数次；如果位置i是1，则需要翻转偶数次
如果位置i是0，而当前cnt为偶数，我们其进行翻转，cnt+1，并在答案上累加1
基于差分的思想，我们在i+k的位置标记一个-1，当枚举到第i+k个元素时，cnt加上这个标记，即在第i个元素进行的翻转到此取消了
最后遍历一下后n-k个元素是否都为1，判断是否合法即可
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> diff(n+1);
        int cnt=0,ans=0;
        for(int i=0;i<=n-k;i++){
            cnt+=diff[i];
            if(!nums[i]&&cnt%2==0){
                cnt++,ans++;
                diff[min(i+k,n)]--;
            }
            if(nums[i]&&cnt%2==1){
                cnt++,ans++;
                diff[min(i+k,n)]--;
            }
        }
        for(int i=n-k+1;i<n;i++){
            cnt+=diff[i];
            if(!nums[i]&&cnt%2==0) ans=-1;
            if(nums[i]&&cnt%2==1) ans=-1;
        }
        return ans;
    }
};
