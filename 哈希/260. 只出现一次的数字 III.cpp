/*
在哈希表中就删除元素，不在则插入元素
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for(auto c:nums){
            if(st.count(c)) st.erase(c);
            else st.insert(c);
        }
        return {*st.begin(),*(next(st.begin()))};
    }
};
