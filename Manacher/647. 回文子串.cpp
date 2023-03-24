/*
Manacher：
记以第i个点作为回文中心的最长回文半径为p[i]
则以第i个点作为回文中心的回文子串数目为p[i]/2
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<int> p(2*n+2);
        vector<char> t(2*n+2);
        int idx=0;
        t[++idx]='#';
        for(int i=0;i<n;i++){
            t[++idx]=s[i];
            t[++idx]='#';
        }
        int M=0,R=0;
        int ans=0;
        for(int i=1;i<=idx;i++){
            if(i>R) p[i]=1;
            else p[i]=min(p[2*M-i],R-i+1);
            while(i-p[i]>=1&&i+p[i]<=idx&&t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(i+p[i]-1>R){
                M=i;
                R=i+p[i]-1;
            }
            ans+=p[i]/2;
        }
        return ans;
    }
};
