/*
双指针枚举右端点，如果新加的字符不唯一，则移动左端点直到它唯一为止
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0,cur=0;
        vector<int> f(128);
        for(int l=0,r=0;r<n;r++){
            f[s[r]]++,cur++;
            while(f[s[r]]>1) f[s[l++]]--,cur--;
            ans=max(ans,cur);
        }
        return ans;
    }
};
