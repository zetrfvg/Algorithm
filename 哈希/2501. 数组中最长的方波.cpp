/*
排序后，哈希表记录所有元素结尾的最长方波的长度
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto c:nums){
            int v=sqrt(c);
            if(v*v==c&&mp.count(v)) mp[c]=mp[v]+1;
            else mp[c]=1;
        }
        int ans=-1;
        for(auto c:mp) if(c.second>1) ans=max(ans,c.second);
        return ans;
    }
};
