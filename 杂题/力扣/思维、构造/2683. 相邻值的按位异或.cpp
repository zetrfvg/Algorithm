/*
所有值异或和为0，则为合法方案
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int s=0;
        for(auto c:derived) s^=c;
        return !s;
    }
};
