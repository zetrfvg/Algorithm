/*
无限数组由无限个该长为n的数组构成
答案由若干个长为n的数组+不超过n的连续个元素组成
原数组和为sum，则答案的组成中有target/sum个长为n的数组
剩下不超过n的连续个元素的和为target%sum
而这些元素可能由原数组头部若干元素和尾部若干元素组成，考虑到这一情况，将原数组扩展一倍，在新数组上双指针找和为target%sum的最短子数组
*/
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();
        int ans=target/sum*n;
        target%=sum;
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        int tot=0,res=1e9;
        for(int l=0,r=0;r<2*n;r++){
            tot+=nums[r];
            while(tot>target) tot-=nums[l++];
            if(tot==target) res=min(res,r-l+1);
        }
        return res==1e9?-1:res+ans;
    }
};
