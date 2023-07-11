/*
双指针：枚举右端点，区间中字符种类超过k时移动左指针
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.size();
        unordered_map<int,int> p;
        int cnt=0,ans=0;
        for(int l=0,r=0;r<n;r++){
            if(!p[s[r]]++) cnt++;
            while(cnt>k) cnt-=!--p[s[l++]];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
