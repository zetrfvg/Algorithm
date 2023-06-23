/*
双指针枚举右端点计数
*/
class Solution {
public:
    int numSub(string s) {
        const int mod=1e9+7;
        int n=s.size();
        int ans=0;
        for(int l=0,r=0;r<n;r++){
            if(s[r]=='0') l=r+1;
            else ans=(ans+r-l+1)%mod;
        }
        return ans;
    }
};
