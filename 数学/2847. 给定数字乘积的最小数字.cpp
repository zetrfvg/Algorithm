/*
降序枚举10以下的因子来分解n，分解完如果n还大于1，即n无法被分解为若干个长度为1的因子，无解
然后将所有因子升序排列得到答案
*/
class Solution {
public:
    string smallestNumber(long long n) {
        if(n<10) return to_string(n);
        string ans;
        for(int i=9;i>1;i--){
            while(n%i==0){
                n/=i;
                ans+='0'+i;
            }
        }
        if(n>1) return "-1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
