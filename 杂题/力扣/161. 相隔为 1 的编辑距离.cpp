/*
分类讨论后模拟即可
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        s+='-',t+='-';
        int n=s.size(),m=t.size(),cnt=0;
        if(n==m){
            for(int i=0;i<n;i++) cnt+=s[i]!=t[i];
        }else if(n<m){
            for(int i=0,j=0;i<n&&j<m;i++,j++){
                if(s[i]!=t[j]){
                    if(s[i]!=t[j+1]) return false;
                    cnt++,j++;
                }
            }
        }else{
            for(int i=0,j=0;i<n&&j<m;i++,j++){
                if(s[i]!=t[j]){
                    if(s[i+1]!=t[j]) return false;
                    cnt++,i++;
                }
            }
        }
        return cnt==1;
    }
};
