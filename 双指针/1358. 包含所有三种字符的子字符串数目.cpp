/*
双指针枚举右端点，找到最短的不包含三个字符区间[l,r]，则以r为右端点满足要求的子串数量为l个
累加答案即可
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> f(3);
        int cnt=0,ok=0,ans=0;
        for(int l=0,r=0;r<n;r++){
            cnt+=!f[s[r]-'a']++;
            while(cnt==3){
                cnt-=!--f[s[l++]-'a'];
                ok=1;
            }
            if(ok) ans+=l;
        }
        return ans;
    }
};
