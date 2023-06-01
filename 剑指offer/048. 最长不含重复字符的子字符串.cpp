/*
双指针计数
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        vector<int> cnt(128);
        for(int l=0,r=0;r<n;r++){
            cnt[s[r]]++;
            while(cnt[s[r]]>1) cnt[s[l++]]--;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
