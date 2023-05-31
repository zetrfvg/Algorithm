/*
先将QWER转化为abcd方便处理，我们首先找出哪些字符需要替换
如s串长16，abc都有3个，d有7个，则需要替换的字符是3个d
然后双指针枚举右端点，找到最短的区间包含有3个d即可，这个区间长度即为需要替换的子串的最小长度
*/
class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        vector<int> cnt(4);
        for(auto &c:s){
            if(c=='Q') c='a';
            else if(c=='W') c='b';
            else if(c=='E') c='c';
            else c='d';
            cnt[c-'a']++;
        }
        for(auto &c:cnt) c=max(0,c-n/4);
        if(!cnt[0]&&!cnt[1]&&!cnt[2]&&!cnt[3]) return 0;
        vector<int> f(4);
        auto check=[&](){
            for(int i=0;i<4;i++){
                if(f[i]<cnt[i]) return false;
            }
            return true;
        };
        int ans=1e9,ok=0;
        for(int l=0,r=0;r<n;r++){
            f[s[r]-'a']++;
            while(check()){
                ok=1;
                f[s[l++]-'a']--;
            }
            if(ok) ans=min(ans,r-l+2);
        }
        return ans;
    }
};
