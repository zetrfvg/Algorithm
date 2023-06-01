/*
双指针模拟
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
