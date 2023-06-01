/*
双指针+multiset模拟
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> st;
        int n=nums.size();
        for(int l=0,r=0;r<n;r++){
            auto p=st.insert(nums[r]);
            if(p!=st.begin()){
                auto q=prev(p);
                if(*p-*q<=valueDiff) return true;
            }
            if(p!=prev(st.end())){
                auto q=next(p);
                if(*q-*p<=valueDiff) return true;
            }
            if(r>=indexDiff){
                st.erase(st.find(nums[l++]));
            }
        }
        return false;
    }
};
