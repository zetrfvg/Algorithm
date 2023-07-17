/*
简单模拟即可
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int n=num1.size(),m=num2.size(),rest=0;
        for(int i=n-1,j=m-1;i>=0||j>=0||rest;i--,j--){
            int x=i>=0?num1[i]-'0':0;
            int y=j>=0?num2[j]-'0':0;
            rest+=x+y;
            ans+='0'+(rest%10);
            rest/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
