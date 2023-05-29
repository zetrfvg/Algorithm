/*
滑动窗口+哈希表模拟即可
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(100010);
        long long s=0,cnt=0,ans=0;
        for(int l=0,r=0;r<n;r++){
            s+=nums[r];
            cnt+=!v[nums[r]]++;
            if(cnt==k) ans=max(ans,s);
            if(r>=k-1){
                if(!--v[nums[l]]) cnt--;
                s-=nums[l++];
            }
        }
        return ans;
    }
};
