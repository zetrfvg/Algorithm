/*
分类讨论，贪心
*/
class Solution {
public:
    string smallestString(string s) {
        int p=0;
        int n=s.size();
        while(p<n&&s[p]=='a') p++;
        if(p==n){
            s.back()='z';
            return s;
        }
        while(p<n){
            if(s[p]=='a') break;
            s[p]--;
            p++;
        }
        return s;
    }
};
