/*
双指针枚举右端点，经典题
*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(auto c:nums) st.insert(c);
        int sz=st.size();
        bool ok=0;
        int cnt=0;
        unordered_map<int,int> p;
        int ans=0;
        for(int l=0,r=0;r<nums.size();r++){
            if(!p[nums[r]]++) cnt++;
            if(cnt==sz) ok=1;
            while(cnt>=sz){
                if(!--p[nums[l++]]) cnt--;
            }
            if(ok) ans+=l;
        }
        return ans;
    }
};
