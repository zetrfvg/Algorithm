/*
双指针枚举各个元素作为子数组的右端点的个数
左指针有三个，l,l1,l2，l为满足[l,r]中的元素都在[minK,maxK]的最远的一个位置
l1是离r最近的等于minK的元素，l2是离r最近的等于maxK的元素
如果r在[minK,maxK]范围内，则累计答案min(l1,l2)-l+1
否则，更新l,l1,l2到位置r+1上
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        int mx=0,mn=1e9;
        for(int l=0,r=0,l1=-1,l2=-1;r<n;r++){
            mx=max(mx,nums[r]);
            mn=min(mn,nums[r]);
            if(mn<minK||mx>maxK){
                mx=0,mn=1e9;
                l1=l2=l=r+1;
                continue;
            }
            if(nums[r]==maxK) l2=r;
            if(nums[r]==minK) l1=r;
            if(mx==maxK&&mn==minK){
                ans+=1LL*min(l1,l2)-l+1;
            }
        }
        return ans;
    }
};
