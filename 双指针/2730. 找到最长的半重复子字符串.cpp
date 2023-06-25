/*
双指针模拟即可
*/
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans=1;
        int cnt=0;
        for(int l=0,r=1;r<s.size();r++){
            if(s[r]==s[r-1]) cnt++;
            while(cnt>1){
                if(s[l]==s[l+1]) cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
