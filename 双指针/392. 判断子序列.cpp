class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int l=0,r=0;
        while(l<n&&r<m) if(s[l]==t[r++]) l++;
        return l==n;
    }
};
