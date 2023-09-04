/*
双指针枚举右端点，用哈希表记录区间中的元素个数，当nums[r]在区间中的数量超过1时移动左指针
*/
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0,cur=0;
        int n=nums.size(),c=0;
        unordered_map<int,int> p;
        for(int l=0,r=0;r<n;r++){
            cur+=1LL*nums[r];
            if(!p[nums[r]]++) c++;
            if(r>=k-1&&c>=m) ans=max(ans,cur);
            if(r>=k-1){
                if(!--p[nums[l]]) c--;
                cur-=nums[l++];
            }
        }
        return ans;
    }
};
