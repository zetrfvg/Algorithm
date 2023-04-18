/*
考虑周期数，如果前一个字符大于等于当前字符，则需要串联一个新的abs
答案=周期数*3-word长度
*/
class Solution {
public:
    int addMinimum(string word) {
        int t=1;
        for(int i=1;i<word.size();i++){
            t+=word[i-1]>=word[i];
        }
        return t*3-word.size();
    }
};
