/*
暴力删去所有part串
*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p,m=part.size();
        while((p=s.find(part))!=string::npos) s.erase(p,m);
        return s;
    }
};
