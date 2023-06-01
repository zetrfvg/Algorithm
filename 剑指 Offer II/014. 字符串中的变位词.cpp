/*
双指针模拟
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size(),m=s1.size();
        vector<int> f(26),g(26);
        for(auto c:s1) f[c-'a']++;
        for(int l=0,r=0;r<n;r++){
            g[s2[r]-'a']++;
            if(g==f) return true;
            if(r>=m-1) g[s2[l++]-'a']--;
        }
        return false;
    }
};
