/*
逆序枚举，一边枚举一边计算哈希值即可
*/
class Solution {
public:
    using ll=long long;
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n=s.size();
        ll fac=1;
        int hash=0,pos;
        for(int i=n-1;i>=n-k;i--){
            hash=(1LL*hash*power+(s[i]-'a'+1))%modulo;
            if(i!=n-k) fac=fac*power%modulo;
        }
        if(hash==hashValue) pos=n-k;
        for(int i=n-k-1;~i;i--){
            hash=((1LL*hash-1LL*(s[i+k]-'a'+1)*fac%modulo+modulo)*power+s[i]-'a'+1)%modulo;
            if(hash==hashValue) pos=i;
        }
        return s.substr(pos,k);
    }
};
