/*
暴力枚举
*/
class Solution {
public:
    bool queryString(string s, int n) {
        int m=s.size();
        auto trans=[](int x){
            string s;
            while(x){
                if(x&1) s+='1';
                else s+='0';
                x>>=1;
            }
            reverse(s.begin(),s.end());
            return s;
        };
        for(int i=1;i<=n;i++){
            if(s.find(trans(i))==string::npos){
                return false;
            }
        }
        return true;
    }
};
