/*
枚举所有长为indexDiff的区间，用一个set来维护区间内的元素
对于新插入的元素nums[i]，我们分别找到离它最近的两个元素，如果二者至少存在一个和nums[i]的差值不超过valueDiff，则返回true
滑动窗口时，要从set中删除左端点的元素
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> st;
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
