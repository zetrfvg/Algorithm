/*
双指针模拟
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
