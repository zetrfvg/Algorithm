/*
以set暴力模拟即可
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for(int i=1;i<=k;i++) st.insert(i);
        int ans=0;
        for(int i=nums.size()-1;~i;i--){
            ans++;
            if(st.count(nums[i])) st.erase(st.find(nums[i]));
            if(!st.size()) return ans;
        }
        return -1;
    }
};
