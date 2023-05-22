/*
单调栈+二分
用一个递减的单调栈来维护已经枚举过的元素
我们枚举元素nums[i]在栈上二分找到最远的一个小于等于nums[i]的元素即可
*/
class Solution {
public:
    int st[50010];
    int top=0;
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!top||nums[i]<nums[st[top]]){
                st[++top]=i;
            }else{
                int l=1,r=top;
                while(l<r){
                    int m=(l+r)>>1;
                    if(nums[st[m]]<=nums[i]) r=m;
                    else l=m+1;
                }
                ans=max(ans,i-st[l]);
            }
        }
        return ans;
    }
};
