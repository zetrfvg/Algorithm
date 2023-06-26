/*
简单计数
*/
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for(auto &c:s) cnt[c-'a']++;
        for(auto &c:t) cnt[c-'a']--;
        int ans=0;
        for(auto &c:cnt) ans+=abs(c);
        return ans;
    }
};
