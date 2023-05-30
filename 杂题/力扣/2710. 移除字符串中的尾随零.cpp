/*
模拟即可
*/
class Solution {
public:
    string removeTrailingZeros(string s) {
        int p=s.size()-1;
        while(s[p]=='0') p--;
        return s.substr(0,p+1);
    }
};
