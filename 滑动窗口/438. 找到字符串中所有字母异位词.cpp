/*
p长为m，滑动窗口枚举所有长为m的区间，判断区间中各个字符的个数与p是否一致即可
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        vector<int> ans;
        vector<int> sc(26),pc(26);
        for(auto c:p) pc[c-'a']++;
        for(int l=0,r=0;r<n;r++){
            sc[s[r]-'a']++;
            if(sc==pc) ans.push_back(l);
            if(r>=m-1) sc[s[l++]-'a']--;
        }
        return ans;
    }
};
