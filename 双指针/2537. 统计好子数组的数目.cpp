/*
双指针枚举右端点，如果区间内的相等下标的数量超过k则移动左指针直到这些数量少于k
则以当前元素为右端点符合要求的子数组数量为l
累加答案即可
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0,cur=0;
        unordered_map<int,int> g;
        int n=nums.size();
        bool ok=0;
        for(int l=0,r=0;r<n;r++){
            cur+=g[nums[r]]++;
            while(cur>=k){
                cur-=--g[nums[l++]];
                ok=1;
            }
            if(ok) ans+=1LL*l;
        }
        return ans;
    }
};
