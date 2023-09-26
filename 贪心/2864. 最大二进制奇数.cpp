/*
串尾放一个1，其余的1按高位优先放
*/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c=count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size();i++){
            if(c>1) c--,s[i]='1';
            else s[i]='0';
        }
        s.back()='1';
        return s;
    }
};
