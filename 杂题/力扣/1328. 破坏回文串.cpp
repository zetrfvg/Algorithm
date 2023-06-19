/*
分类讨论：
1、字符串全为a时，修改最后一个字符为b
2、字符串长度为奇数，且除正中间的字符外都是a时，修改最后一个字符为b
3、否则找到从左边开始数第一个不为a的字符，将其改为a
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1) return "";
        if(count(palindrome.begin(),palindrome.end(),'a')==n){
            palindrome.back()++;
            return palindrome;
        }
        if(n&1&&count(palindrome.begin(),palindrome.end(),'a')==n-1&&palindrome[n/2]!='a'){
            palindrome.back()++;
            return palindrome;
        }
        int p=0;
        while(p<n&&(palindrome[p]=='a'||p*2+1==n)) p++;
        palindrome[p]='a';
        return palindrome;
    }
};
