/*
nums值域不大
维护前后缀个数即可
*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<int> pre(201),suf(201);
        for(auto c:nums) suf[c]++;
        int ans=0;
        for(auto c:nums){
            suf[c]--;
            if(c-diff>=0&&c+diff<=200){
                ans+=pre[c-diff]*suf[c+diff];
            }
            pre[c]++;
        }
        return ans;
    }
};
