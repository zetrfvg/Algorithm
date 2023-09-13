/*
暴力枚举所有子串判断即可
*/
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.size();
        int pos=-1,mx=0;
        auto check=[&](vector<int> &a,vector<int> &b){
            for(int i=0;i<26;i++) if(a[i]!=b[i]) return false;
            return true;
        };
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                vector<int> l(26),r(26);
                for(int j=i;j-i+1<=len;j++){
                    if(s[j]>='a'&&s[j]<='z') l[s[j]-'a']=1;
                    else r[s[j]-'A']=1;
                }
                if(check(l,r)){
                    mx=len;
                    pos=i;
                    break;
                }
            }
        }
        return pos==-1?"":s.substr(pos,mx);
    }
};
