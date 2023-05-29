/*
滑动窗口枚举长为k的子串统计即可
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        auto check=[&](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        int ans=0,cur=0;
        for(int l=0,r=0;r<s.size();r++){
            cur+=check(s[r]);
            ans=max(ans,cur);
            if(r>=k-1) cur-=check(s[l++]);
        }
        return ans;
    }
};
