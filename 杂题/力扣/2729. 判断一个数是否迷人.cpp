/*
简单模拟
*/
class Solution {
public:
    bool isFascinating(int n) {
        vector<int> f(9);
        int a=n*2,b=n*3;
        string s=to_string(n)+to_string(a)+to_string(b);
        if(s.size()!=9) return false;
        for(auto c:s){
            if(c=='0') return false;
            f[c-'1']=1;
        }
        return accumulate(f.begin(),f.end(),0)==9;
    }
};
