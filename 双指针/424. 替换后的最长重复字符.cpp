/*
双指针枚举右端点，如果区间长与区间中最多元素的个数之差超过k则移动左指针
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int mx=0,ans=0;
        vector<int> f(26);
        for(int l=0,r=0;r<n;r++){
            mx=max(mx,++f[s[r]-'A']);
            while(r-l+1-mx>k){
                --f[s[l++]-'A'];
                mx=*max_element(f.begin(),f.end());
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
