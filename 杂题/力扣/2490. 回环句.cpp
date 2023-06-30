/*
按题意模拟
*/
class Solution {
public:
    bool isCircularSentence(string s) {
        char c;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(s[i-1]!=s[i+1]) return 0;
            }
        }
        return s.front()==s.back();
    }
};
