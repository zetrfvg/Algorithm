/*
暴力枚举判断即可
*/
class Solution {
public:
    int countSymmetricIntegers(int l, int r) {
        int ans=0;
        for(int i=l;i<=r;i++){
            string s=to_string(i);
            if(s.size()&1) continue;
            int pre=0,suf=0;
            for(int x=0,y=s.size()-1;x<y;x++,y--){
                pre+=s[x]-'0',suf+=s[y]-'0';
            }
            ans+=pre==suf;
        }
        return ans;
    }
};
