/*
简单贪心
*/
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        while(a&&b&&abs(a-b)>=2){
            if(a>b){
                ans+="aab";
                a-=2,b--;
            }
            if(b>a){
                ans+="bba";
                a--,b-=2;
            }
        }
        while(a&&b) ans+="ab",a--,b--;
        while(a) ans+="a",a--;
        while(b) ans+="b",b--;
        return ans;
    }
};
