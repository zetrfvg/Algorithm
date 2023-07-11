/*
双指针枚举右端点，找到其最长的不含重复字符的子串，如果最长子串长度不小于k，说明存在一个以该点为右端点长为k的合法子串
*/
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        vector<int> cnt(26);
        int n=s.size();
        int ans=0;
        for(int l=0,r=0;r<n;r++){
            cnt[s[r]-'a']++;
            while(cnt[s[r]-'a']>1) cnt[s[l++]-'a']--;
            if(r-l+1>=k) ans++;
        }
        return ans;
    }
};
