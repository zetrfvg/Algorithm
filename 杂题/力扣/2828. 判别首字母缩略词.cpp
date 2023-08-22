/*
模拟即可
*/
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res;
        for(auto &c:words) res+=c[0];
        return res==s;
    }
};
