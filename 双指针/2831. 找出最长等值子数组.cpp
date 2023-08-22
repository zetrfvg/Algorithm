/*
将值相同的元素分为一组，用哈希记录它们的下标
分别处理每一组元素b，双指针枚举右端点，该子数组长为b[r]-b[l]+1，要删除的元素为b[r]-b[l]-r+l，如果要删除的元素超过k，则移动左指针
枚举出答案的最大值即可
*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,vector<int>> p;
        for(int i=0;i<n;i++) p[nums[i]].push_back(i);
        for(auto &[a,b]:p){
            for(int l=0,r=0;r<b.size();r++){
                while(b[r]-b[l]-(r-l)>k) l++;
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};
