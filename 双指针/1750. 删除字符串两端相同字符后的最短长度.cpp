/*
按题意模拟
*/
1class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.size()-1;
        for(int p;l<r&&s[l]==s[r];){
            auto ch=s[l];
            while(l<=r&&ch==s[l]) l++;
            while(l<=r&&ch==s[r]) r--;
        }
        return r-l+1;
    }
};
