/*
双指针枚举右端点，当存在字符超过2时移动左指针
*/
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int ans=0,cnt=0;
        vector<int> f(26);
        for(int l=0,r=0;r<s.size();r++){
            f[s[r]-'a']++;
            while(f[s[r]-'a']>1) f[s[l++]-'a']--;
            ans+=(r-l+1);
        }
        return ans;
    }
};
