/*
先反转整个串，再将每个单词依次反转即可
*/
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        for(int l=0,r=0;r<=s.size();r++){
            if(r==s.size()||s[r]==' '){
                reverse(s.begin()+l,s.begin()+r);
                l=r+1;
            }
        }
    }
};
