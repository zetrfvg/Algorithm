/*
暴力枚举n的所有排列
*/
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=to_string(n);
        sort(num.begin(),num.end());
        do{
            if(num[0]=='0') continue;
            int res=0;
            for(auto c:num) res=res*10+c-'0';
            if(!(res&(res-1))) return true;
        }while(next_permutation(num.begin(),num.end()));
        return false;
    }
};
