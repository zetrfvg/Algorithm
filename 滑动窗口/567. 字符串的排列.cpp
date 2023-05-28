/*
滑动窗口枚举所有长和s1相等的区间，判断它们的各字符的数量是否相等即可
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
